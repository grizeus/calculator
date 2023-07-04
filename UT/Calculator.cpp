#include <gtest/gtest.h>
#include "../include/Calculator.hpp"

struct TestCalc : public ::testing::Test {
	Calculator* calc;
	void SetUp() override {
		ToolsPtr tools (new SDL_Tools());
		calc = new Calculator(tools); 
	}
	void TearDown() override { 
		delete calc; 
	}
};

TEST_F(TestCalc, add) {
	// Arrange
	calc->SetOperator('+');

	// Act
	double result = calc->Compute("2", "2");

	// Assert
	EXPECT_DOUBLE_EQ(result, 4.0);
}

TEST_F(TestCalc, subtract) {
	// Arrange
	calc->SetOperator('-');

	// Act
	double result = calc->Compute("26", "2");

	// Assert
	EXPECT_DOUBLE_EQ(result, 24.0);
}

TEST_F(TestCalc, mult) {
	// Arrange
	calc->SetOperator('*');
	// Act
	double result = calc->Compute("3", "2");

	// Assert
	EXPECT_DOUBLE_EQ(result, 6.0);
}

TEST_F(TestCalc, divide) {
	// Arrange
	calc->SetOperator('/');

	// Act
	double result = calc->Compute("169", "13");

	// Assert
	EXPECT_DOUBLE_EQ(result, 13.0);
}

TEST_F(TestCalc, percent) {
	// Arrange
	calc->SetOperator('%');

	// Act
	double result = calc->Compute("5");

	// Assert
	EXPECT_DOUBLE_EQ(result, 0.05);
}

TEST_F(TestCalc, square) {
	// Arrange
	calc->SetOperator('s');

	// Act
	double result = calc->Compute("12");

	// Assert
	EXPECT_DOUBLE_EQ(result, 144.0);
}

TEST_F(TestCalc, squareRoot) {
	// Arrange
	calc->SetOperator('r');

	// Act
	double result = calc->Compute("169");

	// Assert
	EXPECT_DOUBLE_EQ(result, 13.0);
}

TEST_F(TestCalc, inverse) {
	// Arrange
	calc->SetOperator('i');

	// Act
	double result = calc->Compute("20");

	// Assert
	EXPECT_DOUBLE_EQ(result, 0.05);
}

TEST_F(TestCalc, changeSign) {
	// Arrange
	calc->SetOperand1("20.0");
	// Act
	calc->Processing(PlusMinus);
	std::string expecting = "-20.0";
	// Assert
	EXPECT_EQ(calc->GetOperand1(), expecting);
}

TEST_F(TestCalc, changeSign2) {
	// Arrange
	calc->SetState(State::WaitForOperand2);
	calc->SetOperand2("-20.0");
	calc->SetNegative2(true);
	// Act
	calc->Processing(PlusMinus);
	std::string expecting = "20.0";
	// Assert
	EXPECT_EQ(calc->GetOperand2(), expecting);
}

TEST_F(TestCalc, changeSign3) {
	// Arrange
	calc->SetOperand1("20.0");
	calc->Processing(PlusMinus);
	calc->SetState(State::WaitForOperand2);
	calc->SetOperand2("20.0");
	calc->Processing(PlusMinus);
	// Assert
	EXPECT_EQ(calc->GetOperand2(), calc->GetOperand1());
}

TEST_F(TestCalc, changeSign4) {
	// Arrange
	calc->SetOperand1("-20.0");
	calc->SetNegative1(true);
	calc->Processing(PlusMinus);
	calc->SetState(State::WaitForOperand2);
	calc->SetOperand2("-20.0");
	calc->SetNegative2(true);
	calc->Processing(PlusMinus);
	// Assert
	EXPECT_EQ(calc->GetOperand2(), calc->GetOperand1());
}

int main (int argc, char** argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}