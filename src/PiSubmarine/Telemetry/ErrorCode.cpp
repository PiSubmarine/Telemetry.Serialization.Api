#include "PiSubmarine/Telemetry/ErrorCode.h"

#include <array>
#include <string_view>

namespace PiSubmarine::Telemetry
{
    namespace
    {
        class ErrorCategory final : public std::error_category
        {
        public:
            [[nodiscard]] const char* name() const noexcept override
            {
                return "PiSubmarine.Telemetry.Serialization.Api";
            }

            [[nodiscard]] std::string message(const int condition) const override
            {
                constexpr std::array<std::string_view, 4> Messages{
                    "success",
                    "telemetry serialization failed",
                    "telemetry deserialization failed",
                    "invalid telemetry payload"};

                const auto index = static_cast<std::size_t>(condition);
                if (index >= Messages.size())
                {
                    return "unknown telemetry serialization error";
                }

                return std::string(Messages[index]);
            }
        };
    }

    [[nodiscard]] std::error_code make_error_code(const ErrorCode errorCode) noexcept
    {
        static const ErrorCategory Category;
        return {static_cast<int>(errorCode), Category};
    }
}
