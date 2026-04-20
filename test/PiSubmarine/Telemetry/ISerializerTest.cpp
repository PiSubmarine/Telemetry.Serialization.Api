#include <type_traits>

#include <gtest/gtest.h>

#include "PiSubmarine/Telemetry/ISerializer.h"

namespace PiSubmarine::Telemetry
{
    TEST(ISerializerTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<ISerializer>);
    }
}
