#include <gtest/gtest.h>

#include "monitor/isystemstatus.h"
#include "monitor/statistics.h"

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

namespace {

using namespace sharkstore::monitor;

TEST(Monitor, Basic) {
    ISystemStatus s;
    uint64_t total = 0, available = 0;
    ASSERT_TRUE(s.GetFileSystemUsage(".", &total, &available));
    ASSERT_GT(total, 0);
    ASSERT_GT(available, 0);
    ASSERT_GE(total, available);
}

TEST(Monitor, Statistics) {
    Statistics s;
    s.PushTime(HistogramType::kRaft, 123);
    std::cout << s.ToString() << std::endl;
    s.ToString();
}

} /* namespace  */
