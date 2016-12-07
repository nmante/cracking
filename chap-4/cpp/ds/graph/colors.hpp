#ifndef _COLORS_
#define _COLORS_

#include <string>

namespace colors {

	/* FOREGROUND */
	std::string RST  = "\x1B[0m";
	std::string KRED  = "\x1B[31m";
	std::string KGRN  = "\x1B[32m";
	std::string KYEL  = "\x1B[33m";
	std::string KBLU  = "\x1B[34m";
	std::string KMAG  = "\x1B[35m";
	std::string KCYN  = "\x1B[36m";
	std::string KWHT  = "\x1B[37m";
	std::string KLCYN = "\x1B[96m";

	std::string fred(std::string x){ return KRED + x + RST; }
	std::string fgrn(std::string x){ return KGRN + x + RST; }
	std::string fyel(std::string x){ return KYEL + x + RST; }
	std::string fblu(std::string x){ return KBLU + x + RST; }
	std::string fmag(std::string x){ return KMAG + x + RST; }
	std::string fcyn(std::string x){ return KCYN + x + RST; }
	std::string fwht(std::string x){ return KWHT + x + RST; }
	std::string flcyn(std::string x){ return KLCYN + x + RST; }

	std::string bold(std::string x){ return "\x1B[1m" + x + RST; }
	std::string undl(std::string x){ return "\x1B[4m" + x + RST; }

}

#endif  /* _COLORS_ */
