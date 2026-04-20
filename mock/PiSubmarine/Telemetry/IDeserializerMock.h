#pragma once

#include <gmock/gmock.h>

#include "PiSubmarine/Telemetry/IDeserializer.h"

namespace PiSubmarine::Telemetry
{
    class IDeserializerMock : public IDeserializer
    {
    public:
        using ByteView = std::span<const std::byte>;

        MOCK_METHOD(
            (Error::Api::Result<Api::Snapshot>),
            Deserialize,
            ((ByteView bytes)),
            (const, override));
    };
}
