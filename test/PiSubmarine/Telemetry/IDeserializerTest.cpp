#include <type_traits>

#include <gtest/gtest.h>

#include "PiSubmarine/Telemetry/IDeserializer.h"

namespace PiSubmarine::Telemetry
{
    TEST(IDeserializerTest, IsPolymorphic)
    {
        EXPECT_TRUE(std::is_polymorphic_v<IDeserializer>);
    }
}
