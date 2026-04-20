#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "PiSubmarine/Telemetry/IDeserializerMock.h"
#include "PiSubmarine/Telemetry/ISerializerMock.h"

namespace PiSubmarine::Telemetry
{
    TEST(SerializationMockTest, SerializerMockCanReturnBytes)
    {
        ISerializerMock serializer;
        Api::Snapshot snapshot{};
        const std::vector<std::byte> payload{std::byte{0x01}, std::byte{0x02}};

        EXPECT_CALL(serializer, Serialize(testing::Eq(snapshot)))
            .WillOnce(testing::Return(Error::Api::Result<std::vector<std::byte>>(payload)));

        const auto result = serializer.Serialize(snapshot);
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, payload);
    }

    TEST(SerializationMockTest, DeserializerMockCanReturnSnapshot)
    {
        IDeserializerMock deserializer;
        const std::array<std::byte, 2> payload{std::byte{0xAA}, std::byte{0xBB}};
        Api::Snapshot snapshot{};

        EXPECT_CALL(deserializer, Deserialize(testing::ElementsAreArray(payload)))
            .WillOnce(testing::Return(Error::Api::Result<Api::Snapshot>(snapshot)));

        const auto result = deserializer.Deserialize(std::span<const std::byte>(payload));
        ASSERT_TRUE(result.has_value());
        EXPECT_EQ(*result, snapshot);
    }
}
