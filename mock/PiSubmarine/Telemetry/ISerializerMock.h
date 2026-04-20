#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Telemetry/ISerializer.h"

namespace PiSubmarine::Telemetry
{
    class ISerializerMock : public ISerializer
    {
    public:
        MOCK_METHOD(
            (Error::Api::Result<std::vector<std::byte>>),
            Serialize,
            ((const Api::Snapshot& snapshot)),
            (const, override));
    };
}
