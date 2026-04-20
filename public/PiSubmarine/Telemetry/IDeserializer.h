#pragma once

#include <cstddef>
#include <span>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Telemetry/Api/Snapshot.h"

namespace PiSubmarine::Telemetry
{
    class IDeserializer
    {
    public:
        virtual ~IDeserializer() = default;

        [[nodiscard]] virtual Error::Api::Result<Api::Snapshot> Deserialize(
            std::span<const std::byte> bytes) const = 0;
    };
}
