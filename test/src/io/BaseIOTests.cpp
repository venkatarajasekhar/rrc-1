/**
 *  @autor nikitas
 *  @date 11/2/16
 */

#include <gtest/gtest.h>

#include <rrc/io/FileSystem.h>

TEST(FileTests, openFile) {
    rrc::IOQueue taskQueue;
    rrc::FileSystem fileSystem(taskQueue);

    rrc::File file = fileSystem.createFile();
    std::shared_ptr<rrc::IOResult> result = file.open("test.txt", rrc::Mode::Read);

    EXPECT_EQ(result->isReady(), false);

    while (!taskQueue.empty()) {
        taskQueue.front()();
        taskQueue.pop();
    }

    EXPECT_EQ(result->isReady(), true);
}
