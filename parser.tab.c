/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern char * yytext;
extern int yyleng;
extern int copyInputFlag;
extern int currentLine;

char * inputFormat = "--------------------------------------------------------\n                     Input program:\n--------------------------------------------------------\n\n\n";
char * outputFormat = "\n\n\n--------------------------------------------------------\n                         Output:\n--------------------------------------------------------\n\n\n";

void yyerror(char const *);

void myErrorPrint(int messageCode);

void pushStack();
void popStack();
void compTags();

void checkAttribute();
void storeAttribute();
void necessaryAttributes();
int assignTagNumber();
void attributeValueCheck(int type);
void idCheck();
void radioGroupCheck();
void progressBarCheck();

int linearContentFlag = 0;

char ** stack;
int stackElements = 0;

char ** attributeList;
int attributeCount = 0;

char ** idList;
int idCount = 0;

char * currentCheckedButton;
char ** buttonIds;
int buttonCount = 0;
int currentButtonQuantity = 0;

int currentProgress = 0;
int currentMax = 100;

#line 122 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_3_ = 3,                         /* '<'  */
  YYSYMBOL_4_ = 4,                         /* '>'  */
  YYSYMBOL_5_ = 5,                         /* '/'  */
  YYSYMBOL_6_ = 6,                         /* ':'  */
  YYSYMBOL_7_ = 7,                         /* '!'  */
  YYSYMBOL_8_ = 8,                         /* '='  */
  YYSYMBOL_9_ = 9,                         /* '"'  */
  YYSYMBOL_ELEMENT_NAME = 10,              /* ELEMENT_NAME  */
  YYSYMBOL_ATTRIBUTE_START = 11,           /* ATTRIBUTE_START  */
  YYSYMBOL_ATTRIBUTE_NAME = 12,            /* ATTRIBUTE_NAME  */
  YYSYMBOL_INTEGER = 13,                   /* INTEGER  */
  YYSYMBOL_STRING = 14,                    /* STRING  */
  YYSYMBOL_YYACCEPT = 15,                  /* $accept  */
  YYSYMBOL_program = 16,                   /* program  */
  YYSYMBOL_element_start = 17,             /* element_start  */
  YYSYMBOL_18_1 = 18,                      /* $@1  */
  YYSYMBOL_element_middle = 19,            /* element_middle  */
  YYSYMBOL_20_2 = 20,                      /* $@2  */
  YYSYMBOL_element_end = 21,               /* element_end  */
  YYSYMBOL_22_3 = 22,                      /* $@3  */
  YYSYMBOL_23_4 = 23,                      /* $@4  */
  YYSYMBOL_content = 24,                   /* content  */
  YYSYMBOL_attributes = 25,                /* attributes  */
  YYSYMBOL_attribute = 26,                 /* attribute  */
  YYSYMBOL_27_5 = 27,                      /* $@5  */
  YYSYMBOL_attribute_value = 28,           /* attribute_value  */
  YYSYMBOL_29_6 = 29,                      /* $@6  */
  YYSYMBOL_30_7 = 30                       /* $@7  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   30

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  15
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  16
/* YYNRULES -- Number of rules.  */
#define YYNRULES  22
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  42

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   262


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     7,     9,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     5,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     6,     2,
       3,     8,     4,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,    10,    11,
      12,    13,    14
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int8 yyrline[] =
{
       0,    59,    59,    60,    64,    64,    68,    68,    72,    72,
      73,    73,    74,    78,    79,    83,    84,    88,    88,    92,
      92,    93,    93
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "'<'", "'>'", "'/'",
  "':'", "'!'", "'='", "'\"'", "ELEMENT_NAME", "ATTRIBUTE_START",
  "ATTRIBUTE_NAME", "INTEGER", "STRING", "$accept", "program",
  "element_start", "$@1", "element_middle", "$@2", "element_end", "$@3",
  "$@4", "content", "attributes", "attribute", "$@5", "attribute_value",
  "$@6", "$@7", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-16)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       8,    -9,    12,   -16,   -16,   -16,     2,     9,   -16,     2,
     -16,     4,     0,   -16,   -16,    11,    13,   -16,    10,    -3,
     -16,    16,   -16,    14,   -16,    15,    -2,   -16,    -4,   -16,
      17,   -16,   -16,    18,   -16,    19,    20,   -16,    22,   -16,
     -16,   -16
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     3,     4,     1,     0,     0,     5,     6,
      16,     0,     0,    15,    17,     0,     0,     7,     0,     0,
      14,     0,    12,     0,    18,     0,     0,    13,     0,    10,
       0,    19,    21,     0,     8,     0,     0,    11,     0,    20,
      22,     9
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -16,   -16,   -15,   -16,   -16,   -16,   -16,   -16,   -16,   -16,
     -16,    21,   -16,   -16,   -16,   -16
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     3,     6,     8,    12,    17,    38,    33,    21,
       9,    10,    18,    24,    35,    36
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      20,     4,    25,    30,    15,    16,    27,     4,     4,    31,
      32,     1,     5,     7,    19,    11,    14,    22,    23,    26,
       0,     0,    37,    28,     0,    29,    41,    34,    39,    40,
      13
};

static const yytype_int8 yycheck[] =
{
      15,    10,     5,     5,     4,     5,    21,    10,    10,    13,
      14,     3,     0,    11,     3,     6,    12,     4,     8,     3,
      -1,    -1,     4,     9,    -1,    10,     4,    10,     9,     9,
       9
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,    16,    17,    10,     0,    18,    11,    19,    25,
      26,     6,    20,    26,    12,     4,     5,    21,    27,     3,
      17,    24,     4,     8,    28,     5,     3,    17,     9,    10,
       5,    13,    14,    23,    10,    29,    30,     4,    22,     9,
       9,     4
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    15,    16,    16,    18,    17,    20,    19,    22,    21,
      23,    21,    21,    24,    24,    25,    25,    27,    26,    29,
      28,    30,    28
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     1,     0,     4,     0,     3,     0,     7,
       0,     6,     2,     2,     1,     2,     1,     0,     5,     0,
       5,     0,     5
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: %empty  */
#line 59 "parser.y"
               {printf("%sThe input file is empty.\n\n", outputFormat);}
#line 1156 "parser.tab.c"
    break;

  case 3: /* program: element_start  */
#line 60 "parser.y"
                        {if(copyInputFlag == 0) printf("%sCOMPILED_SUCCESSFULLY\n\n", outputFormat);}
#line 1162 "parser.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 64 "parser.y"
                         {pushStack();}
#line 1168 "parser.tab.c"
    break;

  case 6: /* $@2: %empty  */
#line 68 "parser.y"
                   {necessaryAttributes(); free(attributeList); attributeCount = 0;}
#line 1174 "parser.tab.c"
    break;

  case 8: /* $@3: %empty  */
#line 72 "parser.y"
                                         {compTags();}
#line 1180 "parser.tab.c"
    break;

  case 10: /* $@4: %empty  */
#line 73 "parser.y"
                                   {compTags();}
#line 1186 "parser.tab.c"
    break;

  case 12: /* element_end: '/' '>'  */
#line 74 "parser.y"
                  {popStack();}
#line 1192 "parser.tab.c"
    break;

  case 17: /* $@5: %empty  */
#line 88 "parser.y"
                                           {checkAttribute(); storeAttribute();}
#line 1198 "parser.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 92 "parser.y"
                        {attributeValueCheck(0);}
#line 1204 "parser.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 93 "parser.y"
                         {attributeValueCheck(1); idCheck();}
#line 1210 "parser.tab.c"
    break;


#line 1214 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 96 "parser.y"

void attributeValueCheck(int type)
{
	if(type == 0)
	{
		if(strcmp(attributeList[attributeCount - 1], "layout_height") != 0
			&& strcmp(attributeList[attributeCount - 1], "layout_width") != 0
			&& strcmp(attributeList[attributeCount - 1], "padding") != 0
			&& strcmp(attributeList[attributeCount - 1], "progress") != 0
			&& strcmp(attributeList[attributeCount - 1], "max") != 0
			&& strcmp(attributeList[attributeCount - 1], "button_quantity") != 0)
		{
			myErrorPrint(5);
		}
		
		if(strcmp(attributeList[attributeCount - 1], "progress") == 0)
			currentProgress = atoi(yytext);
			
		if(strcmp(attributeList[attributeCount - 1], "max") == 0)
			currentMax = atoi(yytext);
			
		if(strcmp(attributeList[attributeCount - 1], "button_quantity") == 0)
			currentButtonQuantity = atoi(yytext);
	}
	else
	{
		if(strcmp(attributeList[attributeCount - 1],"layout_width") == 0 || strcmp(attributeList[attributeCount - 1],"layout_height") == 0)
		{
			if(strcmp(yytext,"wrap_content") != 0 && strcmp(yytext,"match_parent") != 0)
			{
				myErrorPrint(5);
			}
			return;
		}
		else if(strcmp(attributeList[attributeCount - 1], "padding") == 0
			|| strcmp(attributeList[attributeCount - 1], "progress") == 0
			|| strcmp(attributeList[attributeCount - 1], "max") == 0
			|| strcmp(attributeList[attributeCount - 1], "button_quantity") == 0)
		{
			myErrorPrint(5);
		}
		
		if(strcmp(attributeList[attributeCount - 1], "checkedButton") == 0)
		{
			char * temp = (char *) malloc(sizeof(yytext));
			strcpy(temp, yytext);
			currentCheckedButton = temp;
		}
	}
}

void idCheck()
{
	if(strcmp(attributeList[attributeCount - 1], "id") != 0)
		return;
	
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);
	
	if(idCount == 0)
	{
		idList = (char **) malloc(sizeof(char *));
		idList[0] = temp;
	}
	else
	{
		for(int i = 0; i < idCount; i++)
		{
			if(strcmp(idList[i], temp) == 0)
			{
				myErrorPrint(6);
				return;
			}
		}
		
		char ** newList = (char **) malloc(sizeof(char *) * (idCount + 1));
		
		for(int i = 0; i < idCount; i++)
			newList[i] = idList[i];
	
		newList[idCount] = temp;
		
		free(idList);
		idList = newList;
	}
	idCount++;
	
	if(strcmp(stack[stackElements - 1], "RadioButton") == 0)
	{
		if(buttonCount == 0)
		{
			buttonIds = (char **) malloc(sizeof(char *));
			buttonIds[0] = temp;
		}
		else
		{
			for(int i = 0; i < buttonCount; i++)
			{
				if(strcmp(buttonIds[i], temp) == 0)
				{
					myErrorPrint(6);
					return;
				}
			}
			
			char ** newList = (char **) malloc(sizeof(char *) * (buttonCount + 1));

			for(int i = 0; i < buttonCount; i++)
				newList[i] = buttonIds[i];
		
			newList[buttonCount] = temp;
			
			free(buttonIds);
			buttonIds = newList;
		}
		buttonCount++;
	}
}

void checkAttribute()
{
	int tagNumber = assignTagNumber();
	
	if(strcmp(yytext, "layout_width") != 0 && strcmp(yytext, "layout_height") != 0 && strcmp(yytext, "id") != 0)
	{
		switch(tagNumber)
		{
			case 0:
				myErrorPrint(2);
				break;
			case 1:
				if(strcmp(yytext, "orientation") != 0)
					myErrorPrint(2);
				break;
			case 2:
				if(strcmp(yytext, "text") != 0 && strcmp(yytext, "textColor") != 0)
					myErrorPrint(2);
				break;
			case 3:
				if(strcmp(yytext, "src") != 0 && strcmp(yytext, "padding") != 0)
					myErrorPrint(2);
				break;
			case 4:
				if(strcmp(yytext, "text") != 0 && strcmp(yytext, "padding") != 0)
					myErrorPrint(2);
				break;
			case 5:
				if(strcmp(yytext, "checkedButton") != 0 && strcmp(yytext, "button_quantity") != 0)
					myErrorPrint(2);
				break;
			case 6:
				if(strcmp(yytext, "text") != 0)
					myErrorPrint(2);
				break;
			case 7:
				if(strcmp(yytext, "max") != 0 && strcmp(yytext, "progress") != 0)
					myErrorPrint(2);
				break;
		}

	}
}

void storeAttribute()
{
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);

	if(attributeCount == 0)
	{
		attributeList = (char **) malloc(sizeof(char *));
		attributeList[0] = temp;
	}
	else
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i],temp) == 0)
			{
				myErrorPrint(3);
				return;
			}
		}
		
		char ** newList = (char **) malloc(sizeof(char *) * (attributeCount + 1));
		
		for(int i = 0; i < attributeCount; i++)
			newList[i] = attributeList[i];
	
		newList[attributeCount] = temp;
		
		free(attributeList);
		attributeList = newList;
	}
	attributeCount++;
}

void necessaryAttributes()
{	
	int flag1 = 0;
	int flag2 = 0;
	int flag3 = 0;
	
	int tagNumber = assignTagNumber();
	
	if(attributeCount < 2)
	{
		myErrorPrint(4);
		return;
	}
	
	for(int i = 0; i < attributeCount; i++)
	{
		if(strcmp(attributeList[i], "layout_width") == 0)
		{
			flag1 = 1;
			break;
		}
	}
	
	for(int i = 0; i < attributeCount; i++)
	{
		if(strcmp(attributeList[i], "layout_height") == 0)
		{
			flag2 = 1;
			break;
		}
	}
	
	if(tagNumber == 3)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "src") == 0)
			{
				flag3 = 1;
				break;
			}
		}

	}
	else if(tagNumber == 5)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "button_quantity") == 0)
			{
				flag3 = 1;
				break;
			}
		}
	}
	else if(tagNumber == 2 || tagNumber == 4 || tagNumber == 6)
	{
		for(int i = 0; i < attributeCount; i++)
		{
			if(strcmp(attributeList[i], "text") == 0)
			{
				flag3 = 1;
				break;
			}
		}
	}
	else flag3 = 1;
	
	if(flag1 == 0 || flag2 == 0 || flag3 == 0)
		myErrorPrint(4);
}

int assignTagNumber()
{
	if(strcmp(stack[stackElements - 1], "RelativeLayout") == 0)
		return 0;
	else if(strcmp(stack[stackElements - 1], "LinearLayout") == 0)
		return 1;
	else if(strcmp(stack[stackElements - 1], "TextView") == 0)
		return 2;
	else if(strcmp(stack[stackElements - 1], "ImageView") == 0)
		return 3;
	else if(strcmp(stack[stackElements - 1], "Button") == 0)
		return 4;
	else if(strcmp(stack[stackElements - 1], "RadioGroup") == 0)
		return 5;
	else if(strcmp(stack[stackElements - 1], "RadioButton") == 0)
		return 6;
	else if(strcmp(stack[stackElements - 1], "ProgressBar") == 0)
		return 7;
}

void pushStack()
{
	char * temp = (char *) malloc(sizeof(yytext));
	strcpy(temp, yytext);

	if(strcmp(temp, "LinearLayout") == 0)
		linearContentFlag = 1;
	else
		linearContentFlag = 0;

	if(stackElements == 0)
	{
		if(strcmp("LinearLayout", temp) != 0 && strcmp("RelativeLayout", temp) != 0)
			myErrorPrint(7);
	
		stack = (char **) malloc(sizeof(char *));
		stack[0] = temp;
	}
	else
	{
		if(strcmp("RadioButton",temp) == 0 && strcmp("RadioGroup",stack[stackElements - 1]) != 0)
			myErrorPrint(9);
			
		if(strcmp("RadioButton",temp) != 0 && strcmp("RadioGroup",stack[stackElements - 1]) == 0)
			myErrorPrint(10);
	
		char ** newStack = (char **) malloc(sizeof(char *) * (stackElements + 1));
		
		for(int i = 0; i < stackElements; i++)
			newStack[i] = stack[i];
			
		newStack[stackElements] = temp;
		
		free(stack);
		stack = newStack;
	}
	stackElements++;
}

void popStack(){
	if(strcmp("LinearLayout", stack[stackElements - 1]) == 0 && linearContentFlag == 1)
		myErrorPrint(8);

	if(strcmp(stack[stackElements - 1], "RadioGroup") == 0)
	{
		radioGroupCheck();
		free(buttonIds);
		free(currentCheckedButton);
		buttonCount = 0;
		currentButtonQuantity = 0;
	}
		
	if(strcmp(stack[stackElements - 1], "ProgressBar") == 0)
	{
		progressBarCheck();
		currentProgress = 0;
		currentMax = 100;
	}
		
	char ** newStack = (char **) malloc(sizeof(char *) * (stackElements - 1));
		
	for(int i = 0; i < stackElements - 1; i++)
		newStack[i] = stack[i];
	
	free(stack);
	stack = newStack;
	stackElements--;
}

void radioGroupCheck()
{
	if(currentButtonQuantity != buttonCount)
		myErrorPrint(14);

	if(currentCheckedButton)
	{
		if(buttonCount == 0)
		{
			myErrorPrint(12);
			return;
		}
		
		for(int i = 0; i < buttonCount; i++)
		{
			if(strcmp(currentCheckedButton, buttonIds[i]) == 0)
				return;
		}
		myErrorPrint(13);
	}
}

void progressBarCheck()
{
	if(currentProgress < 0 || currentProgress > currentMax)
		myErrorPrint(11);
}

void compTags()
{
	if(strcmp(stack[stackElements - 1], yytext) == 0) 
		popStack();
	else
		myErrorPrint(1);
}

void myErrorPrint(int messageCode)
{
	if(copyInputFlag == 0)
	{
		char * errorText = (char *) malloc(sizeof(char *));
	
		switch(messageCode)
		{
			case 1:
				errorText = "START AND END TAGS DONT MATCH";
				break;
			case 2:
				errorText = "TAG CONTAINS IMPROPER ATTRIBUTE";
				break;
			case 3:
				errorText = "MULTIPLE INSTANCES OF ATTRIBUTE ARE NOT ALLOWED";
				break;
			case 4:
				errorText = "TAG DOES NOT CONTAIN NECESSARY ATTRIBUTES";
				break;
			case 5:
				errorText = "WRONG DATA TYPE IN ATTRIBUTE VALUE";
				break;
			case 6:
				errorText = "ID VALUES MUST BE UNIQUE";
				break;
			case 7:
				errorText = "ROOT TAG MUST BE EITHER LINEARLAYOUT OR RELATIVELAYOUT";
				break;
			case 8:
				errorText = "LINEAR LAYOUT TAG CANNOT BE EMPTY";
				break;
			case 9:
				errorText = "RADIO BUTTON TAGS CAN APPEAR ONLY INSIDE RADIO GROUP TAGS";
				break;
			case 10:
				errorText = "RADIO GROUP TAGS CAN CONTAIN ONLY RADIO BUTTON TAGS";
				break;
			case 11:
				errorText = "PROGRESS ATTRIBUTE VALUE MUST BETWEEN 0 AND MAX";
				break;
			case 12:
				errorText = "RADIO GROUP MUST CONTAIN AT LEAST ONE RADIO BUTTON WITH DEFINED ID FOR THE CHECKED BUTTON ATTRIBUTE TO BE USED";
				break;
			case 13:
				errorText = "CHECKED BUTTON NEEDS TO MATCH THE ID OF A RADIO BUTTON INSIDE THE RADIO GROUP";
				break;
			case 14:
				errorText = "RADIO GROUP MUST CONTAIN AS MANY RADIO BUTTONS AS INDICATED BY THE BUTTON QUANTITY ATTRIBUTE";
				break;
			case 15:
				errorText = "IMPROPER CHARACTER";
				break;
			case 16:
				errorText = "COMMENT CANNOT CONTAIN TWO OR MORE HYPHENS IN A ROW";
				break;
		}
		
		printf("%sLine %d: %s\n\n", outputFormat, currentLine, errorText);

		copyInputFlag = 1;
	}
}

void yyerror(char const *msg)
{
	printf("%sLine %d: UNDEFINED SYNTAX ERROR\n\n", outputFormat, currentLine);
}

int main()
{
	printf("%s", inputFormat);
	yyparse();
	return 0;
}
