#pragma once

#include <cstddef>
#include <vector>

#include "PiSubmarine/Error/Api/Result.h"
#include "PiSubmarine/Telemetry/Api/Snapshot.h"

namespace PiSubmarine::Telemetry
{
    class ISerializer
    {
    public:
        virtual ~ISerializer() = default;

        [[nodiscard]] virtual Error::Api::Result<std::vector<std::byte>> Serialize(
            const Api::Snapshot& snapshot) const = 0;
    };
}
