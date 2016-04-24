// Copyright 2016 Kursakov Evgeny

#include <gtest/gtest.h>
#include <string>
#include <vector>

#include "include/mass_converter.h"

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Create) {
    // Arrange
    MassConverter *converter;

    // Act
    converter = new MassConverter();

    // Assert
    EXPECT_NE(nullptr, converter);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Create_With_Default_Units) {
    // Arrange
    MassConverter converter;

    // Act
    std::vector<MassUnit> units = converter.getUnits();

    // Assert
    std::vector<MassUnit> expected_units = kMassUnitsDefault;
    EXPECT_EQ(units, expected_units);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Create_With_Custom_Units) {
    // Arrange
    std::vector<MassUnit> expected_units = {
            MassUnit(1, "kg"),
            MassUnit(15, "test")
    };

    // Act
    MassConverter converter(expected_units);
    std::vector<MassUnit> units = converter.getUnits();

    // Assert
    EXPECT_EQ(units, expected_units);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Throws_When_Value_Is_Negative) {
    // Arrange
    MassConverter converter;
    double bad_value = -1;

    // Act & Assert
    EXPECT_THROW(
            converter.convert(kMassUnitGram,
                              kMassUnitKilogram,
                              bad_value),
            std::invalid_argument);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Zero_Mass) {
    // Arrange
    MassConverter converter;
    double value = 0;

    // Act
    double result = converter.convert(kMassUnitGram,
                                      kMassUnitKilogram,
                                      value);

    // Assert
    double expected_result = 0;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Gram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.213;

    // Act
    double result = converter.convert(kMassUnitGram,
                                      kMassUnitGram,
                                      value);

    // Assert
    double expected_result = 1.213;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Gram_To_Kilogram) {
    // Arrange
    MassConverter converter;
    double value = 500;

    // Act
    double result = converter.convert(kMassUnitGram,
                                      kMassUnitKilogram,
                                      value);

    // Assert
    double expected_result = 0.5;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_To_Gram) {
    // Arrange
    MassConverter converter;
    double value = 1.2;

    // Act
    double result = converter.convert(kMassUnitKilogram,
                                      kMassUnitGram,
                                      value);

    // Assert
    double expected_result = 1200;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Add_New_Unit) {
    // Arrange
    std::vector<MassUnit> emptyArray;
    MassConverter converter(emptyArray);
    MassUnit unit = MassUnit(3.14, "test");

    // Act
    converter.addUnit(unit);

    // Assert
    MassUnit expected_unit = converter.getUnits()[0];
    EXPECT_EQ(unit, expected_unit);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Clear_Units) {
    // Arrange
    MassConverter converter;

    // Act
    converter.clearUnits();

    // Assert
    EXPECT_TRUE(converter.getUnits().empty());
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_From_String_To_Gram) {
    // Arrange
    MassConverter converter;

    // Act
    double result = converter.from_string("0.1 kg", kMassUnitGram);

    // Assert
    double expected_result = 100;
    EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_From_String_With_Custom_Unit) {
    // Arrange
    MassConverter converter;
    MassUnit unit = MassUnit(1000, "Mg");

    // Act
    converter.addUnit(unit);
    double result = converter.from_string("0.001 Mg", kMassUnitKilogram);

    // Assert
    EXPECT_DOUBLE_EQ(result, 1);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_To_String_With_Default_Precision) {
    // Arrange
    MassConverter converter;
    double value = 42.266;

    // Act
    std::string result = converter.to_string(kMassUnitKilogram, value);

    // Assert
    std::string expected_result = "42.27 kg";
    EXPECT_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Can_Convert_Kilogram_To_String_With_Custom_Precision) {
    // Arrange
    MassConverter converter;
    double value = 42.266182;

    // Act
    std::string result = converter.to_string(kMassUnitKilogram, value, 4);

    // Assert
    std::string expected_result = "42.2662 kg";
    EXPECT_EQ(result, expected_result);
}

TEST(Kursakov_Evgeny_MassConverterTest,
     Throws_When_Parse_Unknown_Unit) {
    // Arrange
    MassConverter converter;

    // Act & Assert
    EXPECT_THROW(converter.from_string("2 om", kMassUnitKilogram),
                 std::logic_error);
}
