cmake_minimum_required(VERSION 3.18.0)

project(parser-lib VERSION 1.0.0 LANGUAGES CXX)

# include_directories("${CMAKE_SOURCE_DIR}/ParserImplementation/Interfaces" "${PROJECT_NAME}/ParserImplementation/Source")

add_library(${PROJECT_NAME} 
	chVisitor.cpp
	Interfaces/chVisitor.h
	DOBVisitor.cpp 
	Interfaces/DOBVisitor.h
	Parser.cpp
	Interfaces/Parser.h
	Interfaces/Sink.h
	Interfaces/Source.h
	SteamSink.cpp
	Interfaces/SteamSink.h
	SteamSource.cpp
	Interfaces/SteamSource.h
	StringSink.cpp
	Interfaces/StringSink.h
	StringSource.cpp
	Interfaces/StringSource.h
	Interfaces/Visitor.h
	XMLobj.cpp
	Factories.cpp
	Interfaces/XMLobj.h
	Interfaces/DecoratorSource.h
	Interfaces/DecoratorVisitor.h
	Interfaces/DecoratorSink.h
	Interfaces/Factories.h
	Interfaces/ParserIntf.h
	Interfaces/DecoratorParser.h
	)

target_include_directories(${PROJECT_NAME} PUBLIC Interfaces)
target_link_libraries(${PROJECT_NAME} CONAN_PKG::spdlog CONAN_PKG::gtest)