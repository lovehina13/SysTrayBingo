#pragma once

#include <gtest/gtest.h>

class MyTest : public testing::Test {
  protected:
    void SetUp() override;
    void TearDown() override;
};
