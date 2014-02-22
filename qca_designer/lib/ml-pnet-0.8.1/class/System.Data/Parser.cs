// created by jay 0.7 (c) 1998 Axel.Schreiner@informatik.uni-osnabrueck.de

#line 2 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
//
// Parser.jay
//
// Author:
//   Juraj Skripsky (juraj@hotfeet.ch)
//
// (C) 2004 HotFeet GmbH (http://www.hotfeet.ch)
//

using System;
using System.Collections;
using System.Data;

namespace Mono.Data.SqlExpressions {

	internal class Parser {
		static Parser ()
		{
			if (Environment.GetEnvironmentVariable ("MONO_DEBUG_SQLEXPRESSIONS") != null)
				yacc_verbose_flag = 2;
		}

		bool cacheAggregationResults = false;
		DataRow[] aggregationRows = null;
		static int yacc_verbose_flag;
		
		//called by DataTable.Select
		//called by DataColumn.set_Expression //FIXME: enable cache in this case?
		public Parser () {
			ErrorOutput = System.IO.TextWriter.Null;
			cacheAggregationResults = true;
		}
		
		//called by DataTable.Compute
		public Parser (DataRow[] aggregationRows)
		{
			ErrorOutput = System.IO.TextWriter.Null;
			this.aggregationRows = aggregationRows;
		}
		
		public IExpression Compile (string sqlExpr)
		{
			try {
				Tokenizer tokenizer = new Tokenizer (sqlExpr);
				if (yacc_verbose_flag > 1)
					return (IExpression) yyparse (tokenizer,
						new yydebug.yyDebugSimple ());
				else
					return (IExpression) yyparse (tokenizer);
			} catch (yyParser.yyException e) {
				throw new SyntaxErrorException (String.Format ("Expression '{0}' is invalid.", sqlExpr));
			}
		}
#line default

  /** error output stream.
      It should be changeable.
    */
  public System.IO.TextWriter ErrorOutput = System.Console.Out;

  /** simplified error message.
      @see <a href="#yyerror(java.lang.String, java.lang.String[])">yyerror</a>
    */
  public void yyerror (string message) {
    yyerror(message, null);
  }

  /** (syntax) error message.
      Can be overwritten to control message format.
      @param message text to be displayed.
      @param expected vector of acceptable tokens, if available.
    */
  public void yyerror (string message, string[] expected) {
    if ((expected != null) && (expected.Length  > 0)) {
      ErrorOutput.Write (message+", expecting");
      for (int n = 0; n < expected.Length; ++ n)
        ErrorOutput.Write (" "+expected[n]);
        ErrorOutput.WriteLine ();
    } else
      ErrorOutput.WriteLine (message);
  }

  /** debugging support, requires the package jay.yydebug.
      Set to null to suppress debugging messages.
    */
  protected yydebug.yyDebug debug;

  protected static  int yyFinal = 25;
  public static  string [] yyRule = {
    "$accept : Expr",
    "Expr : BoolExpr",
    "Expr : ArithExpr",
    "BoolExpr : PAROPEN BoolExpr PARCLOSE",
    "BoolExpr : BoolExpr AND BoolExpr",
    "BoolExpr : BoolExpr OR BoolExpr",
    "BoolExpr : NOT BoolExpr",
    "BoolExpr : Predicate",
    "Predicate : CompPredicate",
    "Predicate : IsPredicate",
    "Predicate : LikePredicate",
    "Predicate : InPredicate",
    "CompPredicate : ArithExpr CompOp ArithExpr",
    "CompOp : EQ",
    "CompOp : NE",
    "CompOp : LT",
    "CompOp : GT",
    "CompOp : LE",
    "CompOp : GE",
    "LE : LT EQ",
    "NE : LT GT",
    "GE : GT EQ",
    "ArithExpr : PAROPEN ArithExpr PARCLOSE",
    "ArithExpr : ArithExpr MUL ArithExpr",
    "ArithExpr : ArithExpr DIV ArithExpr",
    "ArithExpr : ArithExpr MOD ArithExpr",
    "ArithExpr : ArithExpr PLUS ArithExpr",
    "ArithExpr : ArithExpr MINUS ArithExpr",
    "ArithExpr : MINUS ArithExpr",
    "ArithExpr : Function",
    "ArithExpr : Value",
    "Value : LiteralValue",
    "Value : ColumnValue",
    "LiteralValue : StringLiteral",
    "LiteralValue : NumberLiteral",
    "LiteralValue : DateLiteral",
    "LiteralValue : BoolLiteral",
    "BoolLiteral : TRUE",
    "BoolLiteral : FALSE",
    "ColumnValue : ColumnName",
    "ColumnValue : PARENT DOT ColumnName",
    "ColumnValue : PARENT PAROPEN RelationName PARCLOSE DOT ColumnName",
    "ColumnValue : CHILD DOT ColumnName",
    "ColumnValue : CHILD PAROPEN RelationName PARCLOSE DOT ColumnName",
    "ColumnName : Identifier",
    "RelationName : Identifier",
    "Function : CalcFunction",
    "Function : AggFunction",
    "AggFunction : AggFunctionName PAROPEN ColumnValue PARCLOSE",
    "AggFunctionName : COUNT",
    "AggFunctionName : SUM",
    "AggFunctionName : AVG",
    "AggFunctionName : MAX",
    "AggFunctionName : MIN",
    "AggFunctionName : STDEV",
    "AggFunctionName : VAR",
    "CalcFunction : IIF PAROPEN BoolExpr COMMA Expr COMMA Expr PARCLOSE",
    "CalcFunction : SUBSTRING PAROPEN Expr COMMA NumberLiteral COMMA NumberLiteral PARCLOSE",
    "CalcFunction : ISNULL PAROPEN ColumnValue COMMA Expr PARCLOSE",
    "CalcFunction : LEN PAROPEN Expr PARCLOSE",
    "CalcFunction : TRIM PAROPEN Expr PARCLOSE",
    "CalcFunction : CONVERT PAROPEN Expr COMMA TypeSpecifier PARCLOSE",
    "TypeSpecifier : StringLiteral",
    "TypeSpecifier : Identifier",
    "IsPredicate : ColumnValue IS NULL",
    "IsPredicate : ColumnValue IS NOT NULL",
    "LikePredicate : ArithExpr LIKE StringLiteral",
    "LikePredicate : ArithExpr NOT LIKE StringLiteral",
    "InPredicate : ColumnValue IN InPredicateValue",
    "InPredicate : ColumnValue NOT IN InPredicateValue",
    "InPredicateValue : PAROPEN InValueList PARCLOSE",
    "InValueList : LiteralValue",
    "InValueList : InValueList COMMA LiteralValue",
  };
  protected static  string [] yyNames = {    
    "end-of-file",null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,null,null,null,null,null,null,null,
    null,null,null,null,null,null,null,"PAROPEN","PARCLOSE","AND","OR",
    "NOT","TRUE","FALSE","NULL","PARENT","CHILD","EQ","LT","GT","PLUS",
    "MINUS","MUL","DIV","MOD","DOT","COMMA","IS","IN","LIKE","COUNT",
    "SUM","AVG","MAX","MIN","STDEV","VAR","IIF","SUBSTRING","ISNULL",
    "LEN","TRIM","CONVERT","StringLiteral","NumberLiteral","DateLiteral",
    "Identifier","FunctionName","UMINUS",
  };

  /** index-checked interface to yyNames[].
      @param token single character or %token value.
      @return token name or [illegal] or [unknown].
    */
  public static string yyname (int token) {
    if ((token < 0) || (token > yyNames.Length)) return "[illegal]";
    string name;
    if ((name = yyNames[token]) != null) return name;
    return "[unknown]";
  }

  /** computes list of expected tokens on error by tracing the tables.
      @param state for which to compute the list.
      @return list of token names.
    */
  protected string[] yyExpecting (int state) {
    int token, n, len = 0;
    bool[] ok = new bool[yyNames.Length];

    if ((n = yySindex[state]) != 0)
      for (token = n < 0 ? -n : 0;
           (token < yyNames.Length) && (n+token < yyTable.Length); ++ token)
        if (yyCheck[n+token] == token && !ok[token] && yyNames[token] != null) {
          ++ len;
          ok[token] = true;
        }
    if ((n = yyRindex[state]) != 0)
      for (token = n < 0 ? -n : 0;
           (token < yyNames.Length) && (n+token < yyTable.Length); ++ token)
        if (yyCheck[n+token] == token && !ok[token] && yyNames[token] != null) {
          ++ len;
          ok[token] = true;
        }

    string [] result = new string[len];
    for (n = token = 0; n < len;  ++ token)
      if (ok[token]) result[n++] = yyNames[token];
    return result;
  }

  /** the generated parser, with debugging messages.
      Maintains a state and a value stack, currently with fixed maximum size.
      @param yyLex scanner.
      @param yydebug debug message writer implementing yyDebug, or null.
      @return result of the last reduction, if any.
      @throws yyException on irrecoverable parse error.
    */
  public Object yyparse (yyParser.yyInput yyLex, Object yyd)
				 {
    this.debug = (yydebug.yyDebug)yyd;
    return yyparse(yyLex);
  }

  /** initial size and increment of the state/value stack [default 256].
      This is not final so that it can be overwritten outside of invocations
      of yyparse().
    */
  protected int yyMax;

  /** executed at the beginning of a reduce action.
      Used as $$ = yyDefault($1), prior to the user-specified action, if any.
      Can be overwritten to provide deep copy, etc.
      @param first value for $1, or null.
      @return first.
    */
  protected Object yyDefault (Object first) {
    return first;
  }

  /** the generated parser.
      Maintains a state and a value stack, currently with fixed maximum size.
      @param yyLex scanner.
      @return result of the last reduction, if any.
      @throws yyException on irrecoverable parse error.
    */
  public Object yyparse (yyParser.yyInput yyLex)
				{
    if (yyMax <= 0) yyMax = 256;			// initial size
    int yyState = 0;                                   // state stack ptr
    int [] yyStates = new int[yyMax];	                // state stack 
    Object yyVal = null;                               // value stack ptr
    Object [] yyVals = new Object[yyMax];	        // value stack
    int yyToken = -1;					// current input
    int yyErrorFlag = 0;				// #tks to shift

    int yyTop = 0;
    goto skip;
    yyLoop:
    yyTop++;
    skip:
    for (;; ++ yyTop) {
      if (yyTop >= yyStates.Length) {			// dynamically increase
        int[] i = new int[yyStates.Length+yyMax];
        yyStates.CopyTo (i, 0);
        yyStates = i;
        Object[] o = new Object[yyVals.Length+yyMax];
        yyVals.CopyTo (o, 0);
        yyVals = o;
      }
      yyStates[yyTop] = yyState;
      yyVals[yyTop] = yyVal;
      if (debug != null) debug.push(yyState, yyVal);

      yyDiscarded: for (;;) {	// discarding a token does not change stack
        int yyN;
        if ((yyN = yyDefRed[yyState]) == 0) {	// else [default] reduce (yyN)
          if (yyToken < 0) {
            yyToken = yyLex.advance() ? yyLex.token() : 0;
            if (debug != null)
              debug.lex(yyState, yyToken, yyname(yyToken), yyLex.value());
          }
          if ((yyN = yySindex[yyState]) != 0 && ((yyN += yyToken) >= 0)
              && (yyN < yyTable.Length) && (yyCheck[yyN] == yyToken)) {
            if (debug != null)
              debug.shift(yyState, yyTable[yyN], yyErrorFlag-1);
            yyState = yyTable[yyN];		// shift to yyN
            yyVal = yyLex.value();
            yyToken = -1;
            if (yyErrorFlag > 0) -- yyErrorFlag;
            goto yyLoop;
          }
          if ((yyN = yyRindex[yyState]) != 0 && (yyN += yyToken) >= 0
              && yyN < yyTable.Length && yyCheck[yyN] == yyToken)
            yyN = yyTable[yyN];			// reduce (yyN)
          else
            switch (yyErrorFlag) {
  
            case 0:
              yyerror(String.Format ("syntax error, got token `{0}'", yyname (yyToken)), yyExpecting(yyState));
              if (debug != null) debug.error("syntax error");
              goto case 1;
            case 1: case 2:
              yyErrorFlag = 3;
              do {
                if ((yyN = yySindex[yyStates[yyTop]]) != 0
                    && (yyN += Token.yyErrorCode) >= 0 && yyN < yyTable.Length
                    && yyCheck[yyN] == Token.yyErrorCode) {
                  if (debug != null)
                    debug.shift(yyStates[yyTop], yyTable[yyN], 3);
                  yyState = yyTable[yyN];
                  yyVal = yyLex.value();
                  goto yyLoop;
                }
                if (debug != null) debug.pop(yyStates[yyTop]);
              } while (-- yyTop >= 0);
              if (debug != null) debug.reject();
              throw new yyParser.yyException("irrecoverable syntax error");
  
            case 3:
              if (yyToken == 0) {
                if (debug != null) debug.reject();
                throw new yyParser.yyException("irrecoverable syntax error at end-of-file");
              }
              if (debug != null)
                debug.discard(yyState, yyToken, yyname(yyToken),
  							yyLex.value());
              yyToken = -1;
              goto yyDiscarded;		// leave stack alone
            }
        }
        int yyV = yyTop + 1-yyLen[yyN];
        if (debug != null)
          debug.reduce(yyState, yyStates[yyV-1], yyN, yyRule[yyN], yyLen[yyN]);
        yyVal = yyDefault(yyV > yyTop ? null : yyVals[yyV]);
        switch (yyN) {
case 3:
#line 105 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = (IExpression)yyVals[-1+yyTop];
	}
  break;
case 4:
#line 109 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new BoolOperation (Operation.AND, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 5:
#line 113 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new BoolOperation (Operation.OR, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 6:
#line 117 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Negation ((IExpression)yyVals[0+yyTop]);
	}
  break;
case 12:
#line 132 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Comparison ((Operation)yyVals[-1+yyTop], (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 13:
#line 138 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.EQ; }
  break;
case 14:
#line 139 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.NE; }
  break;
case 15:
#line 140 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.LT; }
  break;
case 16:
#line 141 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.GT; }
  break;
case 17:
#line 142 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.LE; }
  break;
case 18:
#line 143 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = Operation.GE; }
  break;
case 22:
#line 152 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = (IExpression)yyVals[-1+yyTop];
	}
  break;
case 23:
#line 156 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArithmeticOperation (Operation.MUL, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 24:
#line 160 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArithmeticOperation (Operation.DIV, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 25:
#line 164 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArithmeticOperation (Operation.MOD, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 26:
#line 168 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArithmeticOperation (Operation.ADD, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 27:
#line 172 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArithmeticOperation (Operation.SUB, (IExpression)yyVals[-2+yyTop], (IExpression)yyVals[0+yyTop]);
	}
  break;
case 28:
#line 176 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Negative ((IExpression)yyVals[0+yyTop]);
	}
  break;
case 33:
#line 189 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = new Literal (yyVals[0+yyTop]); }
  break;
case 34:
#line 190 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = new Literal (yyVals[0+yyTop]); }
  break;
case 35:
#line 191 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = new Literal (yyVals[0+yyTop]); }
  break;
case 37:
#line 196 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = new Literal (true); }
  break;
case 38:
#line 197 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = new Literal (false); }
  break;
case 39:
#line 202 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ColumnReference ((string)yyVals[0+yyTop]);
	}
  break;
case 40:
#line 206 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ColumnReference (ReferencedTable.Parent, null, (string)yyVals[0+yyTop]);
	}
  break;
case 41:
#line 210 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ColumnReference (ReferencedTable.Parent, (string)yyVals[-3+yyTop], (string)yyVals[0+yyTop]);
	}
  break;
case 42:
#line 214 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ColumnReference (ReferencedTable.Child, null, (string)yyVals[0+yyTop]);
	}
  break;
case 43:
#line 218 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ColumnReference (ReferencedTable.Child, (string)yyVals[-3+yyTop], (string)yyVals[0+yyTop]);
	}
  break;
case 48:
#line 236 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Aggregation (cacheAggregationResults, aggregationRows, (AggregationFunction)yyVals[-3+yyTop], (ColumnReference)yyVals[-1+yyTop]);
	}
  break;
case 49:
#line 242 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Count; }
  break;
case 50:
#line 243 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Sum; }
  break;
case 51:
#line 244 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Avg; }
  break;
case 52:
#line 245 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Max; }
  break;
case 53:
#line 246 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Min; }
  break;
case 54:
#line 247 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.StDev; }
  break;
case 55:
#line 248 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = AggregationFunction.Var; }
  break;
case 56:
#line 253 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new IifFunction ((IExpression)yyVals[-5+yyTop], (IExpression)yyVals[-3+yyTop], (IExpression)yyVals[-1+yyTop]);
	}
  break;
case 57:
#line 257 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		long arg1 = (long) yyVals[-3+yyTop];
		long arg2 = (long) yyVals[-1+yyTop];
		yyVal = new SubstringFunction ((IExpression)yyVals[-5+yyTop], (int) arg1, (int) arg2);
	}
  break;
case 58:
#line 263 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new IsNullFunction ((IExpression)yyVals[-3+yyTop], (IExpression)yyVals[-1+yyTop]);
	}
  break;
case 59:
#line 267 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new LenFunction ((IExpression)yyVals[-1+yyTop]);
	}
  break;
case 60:
#line 271 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new TrimFunction ((IExpression)yyVals[-1+yyTop]);
	}
  break;
case 61:
#line 275 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ConvertFunction ((IExpression)yyVals[-3+yyTop], (string)yyVals[-1+yyTop]);
	}
  break;
case 64:
#line 287 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Comparison (Operation.EQ, (IExpression)yyVals[-2+yyTop], new Literal (null));
	}
  break;
case 65:
#line 291 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Comparison (Operation.NE, (IExpression)yyVals[-3+yyTop], new Literal (null));
	}
  break;
case 66:
#line 298 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Like ((IExpression)yyVals[-2+yyTop], (string)yyVals[0+yyTop]);
	}
  break;
case 67:
#line 302 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Negation (new Like ((IExpression)yyVals[-3+yyTop], (string)yyVals[-1+yyTop]));
	}
  break;
case 68:
#line 309 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new In ((IExpression)yyVals[-2+yyTop], (IList)yyVals[0+yyTop]);
	}
  break;
case 69:
#line 313 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new Negation (new In ((IExpression)yyVals[-3+yyTop], (IList)yyVals[0+yyTop]));
	}
  break;
case 70:
#line 319 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  { yyVal = yyVals[-1+yyTop]; }
  break;
case 71:
#line 324 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		yyVal = new ArrayList();
		((IList)yyVal).Add (yyVals[0+yyTop]);
	}
  break;
case 72:
#line 329 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
  {
		((IList)(yyVal = yyVals[-2+yyTop])).Add (yyVals[0+yyTop]);
	}
  break;
#line default
        }
        yyTop -= yyLen[yyN];
        yyState = yyStates[yyTop];
        int yyM = yyLhs[yyN];
        if (yyState == 0 && yyM == 0) {
          if (debug != null) debug.shift(0, yyFinal);
          yyState = yyFinal;
          if (yyToken < 0) {
            yyToken = yyLex.advance() ? yyLex.token() : 0;
            if (debug != null)
               debug.lex(yyState, yyToken,yyname(yyToken), yyLex.value());
          }
          if (yyToken == 0) {
            if (debug != null) debug.accept(yyVal);
            return yyVal;
          }
          goto yyLoop;
        }
        if (((yyN = yyGindex[yyM]) != 0) && ((yyN += yyState) >= 0)
            && (yyN < yyTable.Length) && (yyCheck[yyN] == yyState))
          yyState = yyTable[yyN];
        else
          yyState = yyDgoto[yyM];
        if (debug != null) debug.shift(yyStates[yyTop], yyState);
	 goto yyLoop;
      }
    }
  }

   static  short [] yyLhs  = {              -1,
    0,    0,    1,    1,    1,    1,    1,    3,    3,    3,
    3,    4,    8,    8,    8,    8,    8,    8,   10,    9,
   11,    2,    2,    2,    2,    2,    2,    2,    2,    2,
   13,   13,   14,   14,   14,   14,   16,   16,   15,   15,
   15,   15,   15,   17,   18,   12,   12,   20,   21,   21,
   21,   21,   21,   21,   21,   19,   19,   19,   19,   19,
   19,   22,   22,    5,    5,    6,    6,    7,    7,   23,
   24,   24,
  };
   static  short [] yyLen = {           2,
    1,    1,    3,    3,    3,    2,    1,    1,    1,    1,
    1,    3,    1,    1,    1,    1,    1,    1,    2,    2,
    2,    3,    3,    3,    3,    3,    3,    2,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    6,    3,    6,    1,    1,    1,    1,    4,    1,    1,
    1,    1,    1,    1,    1,    8,    8,    6,    4,    4,
    6,    1,    1,    3,    4,    3,    4,    3,    4,    3,
    1,    3,
  };
   static  short [] yyDefRed = {            0,
    0,    0,   37,   38,    0,    0,    0,   49,   50,   51,
   52,   53,   54,   55,    0,    0,    0,    0,    0,    0,
   33,   34,   35,   44,    0,    0,    0,    7,    8,    9,
   10,   11,   29,   30,   31,    0,   36,   39,   46,   47,
    0,    0,    0,    6,    0,    0,    0,    0,    0,    0,
   28,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   13,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   14,   17,   18,    0,    0,    0,    0,    3,   22,
   45,    0,   40,    0,   42,    0,    0,    0,    0,    0,
    0,    0,    4,    0,    0,   19,   20,   21,    0,    0,
   23,   24,   25,   66,    0,    0,    0,   64,    0,   68,
    0,    0,    0,    0,    0,    0,   59,   60,    0,   67,
   69,   65,   71,    0,   48,    0,    0,    0,    0,    0,
   62,   63,    0,   70,    0,   41,   43,    0,    0,   58,
   61,   72,    0,    0,   56,   57,
  };
  protected static  short [] yyDgoto  = {            25,
   26,   27,   28,   29,   30,   31,   32,   71,   72,   73,
   74,   33,   34,   35,   36,   37,   38,   82,   39,   40,
   41,  133,  110,  124,
  };
  protected static  short [] yySindex = {         -155,
 -155, -155,    0,    0, -245, -237, -115,    0,    0,    0,
    0,    0,    0,    0, -238, -216, -208, -195, -193, -191,
    0,    0,    0,    0,    0, -224,  -22,    0,    0,    0,
    0,    0,    0,    0,    0, -253,    0,    0,    0,    0,
 -190, -203,  -36,    0,  -22, -292, -256, -292, -256, -115,
    0,    0, -155, -155, -248, -155, -155, -155, -155, -155,
 -204,    0, -217, -189, -115, -115, -115, -115, -115, -210,
 -115,    0,    0,    0, -202, -233, -180, -248,    0,    0,
    0, -174,    0, -172,    0, -153, -244, -186, -183, -164,
 -163, -167,    0, -147, -197,    0,    0,    0, -213, -213,
    0,    0,    0,    0, -113, -180, -160,    0, -249,    0,
 -145, -161, -152, -155, -179, -155,    0,    0, -242,    0,
    0,    0,    0, -229,    0, -256, -256, -154, -133, -134,
    0,    0, -114,    0, -249,    0,    0, -155, -149,    0,
    0,    0, -112, -106,    0,    0,
  };
  protected static  short [] yyRindex = {            0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   42,   43,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -75,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   27,    0,    0,    0,    0,   23,   37,
    0,    0,    0,    0,    2,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,
  };
  protected static  short [] yyGindex = {          -51,
   20,   32,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -109,    3,    0,  -38,  101,    0,    0,
    0,    0,   47,    0,
  };
  protected static  short [] yyTable = {           123,
   32,   12,   88,   81,   90,   91,   92,   75,   83,   52,
   85,   46,    3,    4,   59,   60,    5,    6,   53,   48,
   42,   44,   26,   76,   77,  142,    5,  107,  134,   47,
  108,  114,   43,   45,   59,   60,   27,   49,   51,   24,
   54,    1,    2,   21,   22,   23,  135,   24,   55,   96,
  131,   97,   52,  132,   79,   59,   60,   89,   67,   68,
   69,   56,  128,   57,  130,   58,   78,   52,   52,   52,
   52,   52,   87,   52,   95,  106,  109,   98,   93,   94,
  111,   86,  104,  112,   45,  113,  143,  136,  137,  115,
   45,   45,  116,  117,  118,  120,   99,  100,  101,  102,
  103,    1,  105,  122,   80,    2,    3,    4,  119,    5,
    6,   59,  125,  126,  129,    7,   65,   66,   67,   68,
   69,  138,  127,  140,    8,    9,   10,   11,   12,   13,
   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
   24,   50,  139,  141,  144,  145,    3,    4,   84,    5,
    6,  146,  121,    0,    0,    7,   65,   66,   67,   68,
   69,    0,    0,    0,    8,    9,   10,   11,   12,   13,
   14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
   24,   15,    0,    0,    0,    0,   15,   15,    0,   15,
   15,    0,    0,    0,    0,   15,    0,    0,    0,    0,
    0,    0,    0,    0,   15,   15,   15,   15,   15,   15,
   15,   15,   15,   15,   15,   15,   15,   15,   15,   15,
   15,   80,    0,    0,   61,    0,    0,    0,    0,    0,
   62,   63,   64,   65,   66,   67,   68,   69,   61,    0,
    0,    0,   70,    0,   62,   63,   64,   65,   66,   67,
   68,   69,    0,    0,    0,    0,   70,    0,   32,   12,
   12,   12,    0,    0,    0,    0,    0,   32,   32,   32,
   32,   32,   32,   32,   32,    0,   32,   12,    0,   32,
   26,   26,   26,   26,    5,    0,    5,    0,    0,   26,
   26,   26,   26,   26,   27,   27,   27,   27,   26,    1,
    2,   26,    5,   27,   27,   27,   27,   27,    0,    0,
    0,    0,   27,    0,   16,   27,    0,    1,    2,   16,
   16,    0,   16,   16,    0,    0,    0,    0,   16,    0,
    0,    0,    0,    0,    0,    0,    0,   16,   16,   16,
   16,   16,   16,   16,   16,   16,   16,   16,   16,   16,
   16,   16,   16,   16,
  };
  protected static  short [] yyCheck = {           109,
    0,    0,   54,  296,   56,   57,   58,  261,   47,    7,
   49,  257,  262,  263,  259,  260,  265,  266,  257,  257,
    1,    2,    0,  277,  278,  135,    0,  261,  258,  275,
  264,  276,    1,    2,  259,  260,    0,  275,    7,  296,
  257,    0,    0,  293,  294,  295,  276,  296,  257,  267,
  293,  269,   50,  296,  258,  259,  260,   55,  272,  273,
  274,  257,  114,  257,  116,  257,  257,   65,   66,   67,
   68,   69,   53,   71,  279,  278,  257,  267,   59,   60,
   78,   50,  293,  258,   53,  258,  138,  126,  127,  276,
   59,   60,  276,  258,  258,  293,   65,   66,   67,   68,
   69,  257,   71,  264,  258,  261,  262,  263,  276,  265,
  266,  259,  258,  275,  294,  271,  270,  271,  272,  273,
  274,  276,  275,  258,  280,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  257,  276,  258,  294,  258,  262,  263,   48,  265,
  266,  258,  106,   -1,   -1,  271,  270,  271,  272,  273,
  274,   -1,   -1,   -1,  280,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  257,   -1,   -1,   -1,   -1,  262,  263,   -1,  265,
  266,   -1,   -1,   -1,   -1,  271,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  280,  281,  282,  283,  284,  285,
  286,  287,  288,  289,  290,  291,  292,  293,  294,  295,
  296,  258,   -1,   -1,  261,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  270,  271,  272,  273,  274,  261,   -1,
   -1,   -1,  279,   -1,  267,  268,  269,  270,  271,  272,
  273,  274,   -1,   -1,   -1,   -1,  279,   -1,  258,  258,
  259,  260,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
  270,  271,  272,  273,  274,   -1,  276,  276,   -1,  279,
  258,  259,  260,  261,  258,   -1,  260,   -1,   -1,  267,
  268,  269,  270,  271,  258,  259,  260,  261,  276,  258,
  258,  279,  276,  267,  268,  269,  270,  271,   -1,   -1,
   -1,   -1,  276,   -1,  257,  279,   -1,  276,  276,  262,
  263,   -1,  265,  266,   -1,   -1,   -1,   -1,  271,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  280,  281,  282,
  283,  284,  285,  286,  287,  288,  289,  290,  291,  292,
  293,  294,  295,  296,
  };

#line 335 "/home/jeff/dev/dev_apps/sand/qca_designer/lib/ml-pnet-0.8.1/mcs-sources/class/System.Data/Mono.Data.SqlExpressions/Parser.jay"
}
#line default
namespace yydebug {
        using System;
	 public interface yyDebug {
		 void push (int state, Object value);
		 void lex (int state, int token, string name, Object value);
		 void shift (int from, int to, int errorFlag);
		 void pop (int state);
		 void discard (int state, int token, string name, Object value);
		 void reduce (int from, int to, int rule, string text, int len);
		 void shift (int from, int to);
		 void accept (Object value);
		 void error (string message);
		 void reject ();
	 }
	 
	 class yyDebugSimple : yyDebug {
		 void println (string s){
			 Console.Error.WriteLine (s);
		 }
		 
		 public void push (int state, Object value) {
			 println ("push\tstate "+state+"\tvalue "+value);
		 }
		 
		 public void lex (int state, int token, string name, Object value) {
			 println("lex\tstate "+state+"\treading "+name+"\tvalue "+value);
		 }
		 
		 public void shift (int from, int to, int errorFlag) {
			 switch (errorFlag) {
			 default:				// normally
				 println("shift\tfrom state "+from+" to "+to);
				 break;
			 case 0: case 1: case 2:		// in error recovery
				 println("shift\tfrom state "+from+" to "+to
					     +"\t"+errorFlag+" left to recover");
				 break;
			 case 3:				// normally
				 println("shift\tfrom state "+from+" to "+to+"\ton error");
				 break;
			 }
		 }
		 
		 public void pop (int state) {
			 println("pop\tstate "+state+"\ton error");
		 }
		 
		 public void discard (int state, int token, string name, Object value) {
			 println("discard\tstate "+state+"\ttoken "+name+"\tvalue "+value);
		 }
		 
		 public void reduce (int from, int to, int rule, string text, int len) {
			 println("reduce\tstate "+from+"\tuncover "+to
				     +"\trule ("+rule+") "+text);
		 }
		 
		 public void shift (int from, int to) {
			 println("goto\tfrom state "+from+" to "+to);
		 }
		 
		 public void accept (Object value) {
			 println("accept\tvalue "+value);
		 }
		 
		 public void error (string message) {
			 println("error\t"+message);
		 }
		 
		 public void reject () {
			 println("reject");
		 }
		 
	 }
}
// %token constants
 class Token {
  public const int PAROPEN = 257;
  public const int PARCLOSE = 258;
  public const int AND = 259;
  public const int OR = 260;
  public const int NOT = 261;
  public const int TRUE = 262;
  public const int FALSE = 263;
  public const int NULL = 264;
  public const int PARENT = 265;
  public const int CHILD = 266;
  public const int EQ = 267;
  public const int LT = 268;
  public const int GT = 269;
  public const int PLUS = 270;
  public const int MINUS = 271;
  public const int MUL = 272;
  public const int DIV = 273;
  public const int MOD = 274;
  public const int DOT = 275;
  public const int COMMA = 276;
  public const int IS = 277;
  public const int IN = 278;
  public const int LIKE = 279;
  public const int COUNT = 280;
  public const int SUM = 281;
  public const int AVG = 282;
  public const int MAX = 283;
  public const int MIN = 284;
  public const int STDEV = 285;
  public const int VAR = 286;
  public const int IIF = 287;
  public const int SUBSTRING = 288;
  public const int ISNULL = 289;
  public const int LEN = 290;
  public const int TRIM = 291;
  public const int CONVERT = 292;
  public const int StringLiteral = 293;
  public const int NumberLiteral = 294;
  public const int DateLiteral = 295;
  public const int Identifier = 296;
  public const int FunctionName = 297;
  public const int UMINUS = 298;
  public const int yyErrorCode = 256;
 }
 namespace yyParser {
  using System;
  /** thrown for irrecoverable syntax errors and stack overflow.
    */
  public class yyException : System.Exception {
    public yyException (string message) : base (message) {
    }
  }

  /** must be implemented by a scanner object to supply input to the parser.
    */
  public interface yyInput {
    /** move on to next token.
        @return false if positioned beyond tokens.
        @throws IOException on input error.
      */
    bool advance (); // throws java.io.IOException;
    /** classifies current token.
        Should not be called if advance() returned false.
        @return current %token or single character.
      */
    int token ();
    /** associated with current token.
        Should not be called if advance() returned false.
        @return value for token().
      */
    Object value ();
  }
 }
} // close outermost namespace, that MUST HAVE BEEN opened in the prolog
