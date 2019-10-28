/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    STRING = 258,
    CONSTANT = 259,
    DATATYPE = 260,
    IF_K = 261,
    ELSE_K = 262,
    WHILE_K = 263,
    FOR_K = 264,
    RETURN_K = 265,
    BREAK_K = 266,
    CONTINUE_K = 267,
    INPUT_K = 268,
    OUTPUT_K = 269,
    SEMICOLON = 270,
    COMMA = 271,
    OP_MUL = 272,
    BIN_OP_MUL = 273,
    BIN_OP_ADD = 274,
    BIN_OP_SHIFT = 275,
    BIN_OP_REL = 276,
    BIN_OP_EQ = 277,
    BIN_OP_ASSIGN = 278,
    BIN_OP_BAND = 279,
    BIN_OP_BOR = 280,
    BIN_OP_BXOR = 281,
    BIN_OP_LAND = 282,
    BIN_OP_LOR = 283,
    UN_OP = 284,
    OPEN_BRACKET = 285,
    CLOSE_BRACKET = 286,
    OPEN_SQUARE = 287,
    CLOSE_SQUARE = 288,
    OPEN_CURLY = 289,
    CLOSE_CURLY = 290,
    IDENTIFIER = 291
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 11 "parser.y" /* yacc.c:1909  */

	int   ival;
	float fval;
	char  sval[100];

#line 97 "parser.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
