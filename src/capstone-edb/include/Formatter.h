
#ifndef FORMATTER_H_
#define FORMATTER_H_

#include <string>
class QString;

namespace CapstoneEDB {

class Operand;
class Instruction;

class Formatter {
public:
	enum Syntax {
		SyntaxIntel, 
		SyntaxATT
	};

	enum Capitalization {
		UpperCase,
		LowerCase
	};

	struct FormatOptions {
		Syntax         syntax;
		Capitalization capitalization;
		bool           tabBetweenMnemonicAndOperands;
		bool           simplifyRIPRelativeTargets;
	};

public:
	std::string to_string(const Instruction &) const;
	std::string to_string(const Operand &) const;
	std::string register_name(int) const;

	FormatOptions options() const {
		return options_;
	}

	void setOptions(const FormatOptions &options);

private:
	void checkCapitalize(std::string &str, bool canContainHex = true) const;
	QString adjustInstructionText(const Instruction &instruction) const;

private:
	FormatOptions options_ = {SyntaxIntel, LowerCase, false, true};
};

}

#endif
