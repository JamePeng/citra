// Copyright 2015 Citra Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include "core/hle/kernel/session.h"
#include "core/hle/kernel/thread.h"

namespace IPC {

bool CheckBufferMappingTranslation(BufferMappingType mapping_type, u32 size, u32 translation) {
    if (0x8 == translation) {
        return false;
    }
    switch (mapping_type)
    {
    case IPC::InputBuffer:
        if (((size << 4) | 0xA) == translation) {
            return true;
        }
        break;
    case IPC::OutputBuffer:
        if (((size << 4) | 0xC) == translation) {
            return true;
        }
        break;
    case IPC::ReadWriteBuffer:
        if (((size << 4) | 0xE) == translation) {
            return true;
        }
        break;
    }
    return false;
}

} // namespace IPC

namespace Kernel {

Session::Session() {}
Session::~Session() {}

}
