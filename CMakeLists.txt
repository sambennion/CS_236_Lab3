cmake_minimum_required(VERSION 3.17)
project(CS_236_Lab3)

set(CMAKE_CXX_STANDARD 14)

add_executable(CS_236_Lab3 main.cpp CommentAutoma.cpp DatalogProgram.cpp IDAutoma.cpp Lexer.cpp main.cpp MatcherAutomaton.cpp Parameter.cpp Parser.cpp Predicate.cpp Rule.cpp StringAutoma.cpp Token.cpp UndefinedCommentAutoma.cpp UndefinedStringAutoma.cpp Relation.cpp Relation.h Database.cpp Database.h Tuple.cpp Tuple.h Interpreter.cpp Interpreter.h)