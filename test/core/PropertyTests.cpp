/**
 *  @autor tekatod
 *  @date 7/21/16
 */

#include <iostream>
#include <string>
#include "gtest/gtest.h"
#include "rrc/Property.h"


TEST(set_get_check, test_int_set_get) {
    rrc::Property p;
    p.set(42);
    EXPECT_EQ(42, p.get<int>());
}

TEST(set_get_check, test_int_type) {
    rrc::Property p;
    p.set(42);
    ASSERT_TRUE(typeid(int)== typeid(p.get<int>()));
}

TEST(set_get_check, test_float_set_get) {
    rrc::Property p;
    p.set(42.0);
    EXPECT_EQ(42.0, p.get<float>());
}

TEST(set_get_check, test_float_type) {
    rrc::Property p;
    p.set(42.0);
    ASSERT_TRUE(typeid(float)== typeid(p.get<float>()));
}

TEST(set_get_check, test_bool_set_get) {
    rrc::Property p;
    p.set(true);
    EXPECT_EQ(true, p.get<bool>());
}

TEST(set_get_check, test_bool_type) {
    rrc::Property p;
    p.set(true);
    ASSERT_TRUE(typeid(bool)== typeid(p.get<bool>()));
}

TEST(set_get_check, test_string_set_get) {
    rrc::Property p;
    p.set("SorokDva");
    EXPECT_EQ("SorokDva", p.get<std::string>());
}

TEST(set_get_check, test_int_type) {
    rrc::Property p;
    p.set("SorokDva");
    ASSERT_TRUE(typeid(std::string)== typeid(p.get<std::string>()));
}

TEST(set_get_check, non_template_getter_int) {
    rrc::Property p;
    p.set(42);
    EXPECT_EQ(42, p.getInt());
}

TEST(set_get_check, non_template_getter_float) {
    rrc::Property p;
    p.set(42.0);
    EXPECT_EQ(42.0, p.getFloat());
}

TEST(set_get_check, non_template_getter_bool) {
    rrc::Property p;
    p.set(true);
    EXPECT_EQ(true, p.getBool());
}

TEST(set_get_check, non_template_getter_string) {
    rrc::Property p;
    p.set("SorokDva");
    EXPECT_EQ("SorokDva", p.getString());
}

TEST(cast_check, bool_to_float) {
    rrc::Property p;
    p.set(true);
    float t = p.get<float>();
    EXPECT_EQ(float(1), t);

}

TEST(cast_check, bool_to_int) {
    rrc::Property p;
    p.set(true);
    int t = p.get<int>();
    EXPECT_EQ(1, t);
}


TEST(cast_check, bool_to_string) {
    rrc::Property p;
    p.set(true);
    std::string t = p.get<std::string>();
    EXPECT_EQ("1", t);
}

TEST(cast_check, float_to_int) {
    rrc::Property p;
    p.set((float)42.42);
    int t = p.get<int>();
    EXPECT_EQ(42, t);
}

TEST(cast_check, float_to_bool) {
    rrc::Property p;
    p.set((float)42.42);
    bool t = p.get<bool>();
    EXPECT_EQ(true, t);
}

TEST(cast_check, float_to_string) {
    rrc::Property p;
    p.set((float)42.42);
    std::string t = p.get<std::string>();
    EXPECT_EQ("42.419998", t); //because of float
}

TEST(cast_check, int_to_bool) {
    rrc::Property p;
    p.set(42);
    bool t = p.get<bool>();
    EXPECT_EQ(true, t);
}

TEST(cast_check, int_to_float) {
    rrc::Property p;
    p.set(42);
    float t = p.get<float>();
    EXPECT_EQ((float)42, t);
}

TEST(cast_check, int_to_string) {
    rrc::Property p;
    p.set(42);
    std::string t = p.get<std::string>();
    EXPECT_EQ("42", t);
}

TEST(cast_check, string_to_bool) {
    rrc::Property p;
    p.set("true");
    bool t = p.get<bool>();
    EXPECT_EQ(true, t);
}

TEST(cast_check, string_to_float) {
    rrc::Property p;
    p.set("42");
    float t = p.get<float>();
    EXPECT_EQ((float)42, t);
}

TEST(cast_check, string_to_int) {
    rrc::Property p;
    p.set("42");
    int t = p.get<int>();
    EXPECT_EQ(42, t);
}