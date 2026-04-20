#include <gtest/gtest.h>

#include "PiSubmarine/Telemetry/ErrorCode.h"

namespace PiSubmarine::Telemetry
{
    TEST(ErrorCodeTest, ReportsReadableMessageForKnownError)
    {
        EXPECT_EQ(make_error_code(ErrorCode::InvalidPayload).message(), "invalid telemetry payload");
    }
}
