%%
[A-Za-z0-9]+            return ParserBase::ID;
\n                      return ParserBase::NEWLINE;
=                       return ParserBase::EQUALS;
.                       std::cout << "UnknownStuff" << std::endl;
