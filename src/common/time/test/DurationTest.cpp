/* Copyright (c) 2018 vesoft inc. All rights reserved.
 *
 * This source code is licensed under Apache 2.0 License,
 * attached with Common Clause Condition 1.0, found in the LICENSES directory.
 */

#include "base/Base.h"
#include <gtest/gtest.h>
#include "time/Duration.h"

using nebula::time::Duration;

TEST(Duration, elapsedInSeconds) {
    for (int i = 0; i < 5; i++) {
        Duration dur;
        auto start = std::chrono::steady_clock::now();
        sleep(2);
        auto diff = std::chrono::steady_clock::now() - start;
        dur.pause();

        ASSERT_EQ(std::chrono::duration_cast<std::chrono::seconds>(diff).count(),
                  dur.elapsedInSec()) << "Inaccuracy in iteration " << i;
    }
}


TEST(Duration, elapsedInMilliSeconds) {
    Duration dur;
    for (int i = 0; i < 200; i++) {
        dur.reset();
        auto start = std::chrono::steady_clock::now();
        usleep(5000);   // Sleep for 5 ms
        auto diff = std::chrono::steady_clock::now() - start;
        dur.pause();

        // Allow 1ms difference
        ASSERT_LE(std::chrono::duration_cast<std::chrono::milliseconds>(diff).count(),
                  dur.elapsedInMSec()) << "Inaccuracy in iteration " << i;
        ASSERT_GE(std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() + 1,
                  dur.elapsedInMSec()) << "Inaccuracy in iteration " << i;
    }
}


TEST(Duration, elapsedInMicroSeconds) {
    Duration dur;
    for (int i = 0; i < 100; ++i) {
        dur.reset();
        auto start = std::chrono::steady_clock::now();
        usleep(4);   // Sleep for 4us
        auto diff = std::chrono::steady_clock::now() - start;
        dur.pause();
        // Allow 5us difference
        ASSERT_LE(std::chrono::duration_cast<std::chrono::microseconds>(diff).count(),
                  dur.elapsedInUSec()) << "Inaccuracy in iteration " << i;
        ASSERT_GE(std::chrono::duration_cast<std::chrono::microseconds>(diff).count() + 5,
                  dur.elapsedInUSec()) << "Inaccuracy in iteration " << i;
    }
}


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    folly::init(&argc, &argv, true);
    google::SetStderrLogging(google::INFO);

    return RUN_ALL_TESTS();
}

