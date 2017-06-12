/*
 *      Copyright (c) 2017 Programmer Woogwei (woogwei@outlook.com)
 *              ALL RIGHTS RESERVED
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    Library General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Library General Public License for more details.
 *
 *    You should have received a copy of the GNU Library General Public
 *    License along with this program; if not, write to the Free
 *    Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
 *    Boston, MA 02110-1301, USA.
 */
#ifndef TYPE_H
#define TYPE_H

enum typDataType
{
  CMODELGEN_DATATYPE_PREFERRED,
  CMODELGEN_DATATYPE_WIDE,
  CMODELGEN_DATATYPE_EXTENDED
};

enum typSignal
{
  CMODELGEN_SIGNAL_REG,
  CMODELGEN_SIGNAL_TRI,
  CMODELGEN_SIGNAL_TRI0,
  CMODELGEN_SIGNAL_TRI1,
  CMODELGEN_SIGNAL_TRIAND,
  CMODELGEN_SIGNAL_TRIOR,
  CMODELGEN_SIGNAL_SUPPLY0,
  CMODELGEN_SIGNAL_SUPPLY1,
  CMODELGEN_SIGNAL_NONE
};

enum typLogic
{
  // N-output.
  CMODELGEN_LOGIC_BUFZ,
  CMODELGEN_LOGIC_BUF,
  CMODELGEN_LOGIC_NOT,
  // N-input.
  CMODELGEN_LOGIC_AND,
  CMODELGEN_LOGIC_NAND,
  CMODELGEN_LOGIC_OR,
  CMODELGEN_LOGIC_NOR,
  CMODELGEN_LOGIC_XOR,
  CMODELGEN_LOGIC_XNOR,
  // Only one output.
  CMODELGEN_LOGIC_PULLUP,
  CMODELGEN_LOGIC_PULLDOWN,
  // Enable.
  CMODELGEN_LOGIC_BUFIF0,
  CMODELGEN_LOGIC_BUFIF1,
  CMODELGEN_LOGIC_NOTIF0,
  CMODELGEN_LOGIC_NOTIF1,
  CMODELGEN_LOGIC_NONE
};

enum typLpm
{
  CMODELGEN_LPM_ADD,
  CMODELGEN_LPM_SUB,
  CMODELGEN_LPM_MUL,
  CMODELGEN_LPM_DIV,
  CMODELGEN_LPM_MOD,
  CMODELGEN_LPM_POW,
  CMODELGEN_LPM_EQ,
  CMODELGEN_LPM_NE,
  CMODELGEN_LPM_GE,
  CMODELGEN_LPM_GT,
  CMODELGEN_LPM_TRI_EQ,
  CMODELGEN_LPM_TRI_NE,
  CMODELGEN_LPM_SHL,
  CMODELGEN_LPM_SHR,
  CMODELGEN_LPM_RDCT_AND,
  CMODELGEN_LPM_RDCT_NAND,
  CMODELGEN_LPM_RDCT_OR,
  CMODELGEN_LPM_RDCT_NOR,
  CMODELGEN_LPM_RDCT_XOR,
  CMODELGEN_LPM_RDCT_XNOR,
  CMODELGEN_LPM_SEXT,
  CMODELGEN_LPM_MUX,
  CMODELGEN_LPM_PART_VP,
  CMODELGEN_LPM_PART_PV,
  CMODELGEN_LPM_CONCAT,
  CMODELGEN_LPM_REPEAT,
  CMODELGEN_LPM_ARRAY,
  CMODELGEN_LPM_UFUNC,
  CMODELGEN_LPM_NONE
};

enum typOperator
{
  CMODELGEN_OPERATOR_ADD,
  CMODELGEN_OPERATOR_SUB,
  CMODELGEN_OPERATOR_MUL,
  CMODELGEN_OPERATOR_DIV,
  CMODELGEN_OPERATOR_MOD,
  CMODELGEN_OPERATOR_POW,
  CMODELGEN_OPERATOR_AND,
  CMODELGEN_OPERATOR_OR,
  CMODELGEN_OPERATOR_NAND,
  CMODELGEN_OPERATOR_NOR,
  CMODELGEN_OPERATOR_XOR,
  CMODELGEN_OPERATOR_XNOR,
  CMODELGEN_OPERATOR_EQ,
  CMODELGEN_OPERATOR_NE,
  CMODELGEN_OPERATOR_GE,
  CMODELGEN_OPERATOR_GT,
  CMODELGEN_OPERATOR_LE,
  CMODELGEN_OPERATOR_LT,
  CMODELGEN_OPERATOR_CASE_EQ,
  CMODELGEN_OPERATOR_CASE_NE,
  CMODELGEN_OPERATOR_SHL,
  CMODELGEN_OPERATOR_SHR,
  CMODELGEN_OPERATOR_ASHR,
  CMODELGEN_OPERATOR_NOT,
  CMODELGEN_OPERATOR_LOGIC_NOT,
  CMODELGEN_OPERATOR_LOGIC_AND,
  CMODELGEN_OPERATOR_LOGIC_OR,
  CMODELGEN_OPERATOR_NONE
};

enum typScope
{
  CMODELGEN_SCOPE_MODULE,
  CMODELGEN_SCOPE_BEGIN,
  CMODELGEN_SCOPE_FUNCTION,
  CMODELGEN_SCOPE_TASK,
  CMODELGEN_SCOPE_NONE
};

enum typExpression
{
  CMODELGEN_EXPRESSION_SELECT,
  CMODELGEN_EXPRESSION_UNARY,
  CMODELGEN_EXPRESSION_BINARY,
  CMODELGEN_EXPRESSION_CONDITIONAL,
  CMODELGEN_EXPRESSION_NUMBER,
  CMODELGEN_EXPRESSION_SIGNAL,
  CMODELGEN_EXPRESSION_ARRAY,
  CMODELGEN_EXPRESSION_STRING,
  CMODELGEN_EXPRESSION_CONCAT,
  CMODELGEN_EXPRESSION_FUNCTION,
  CMODELGEN_EXPRESSION_SFUNCTION,
  CMODELGEN_EXPRESSION_NONE
};

enum typStatement
{
  CMODELGEN_STATEMENT_CASEZ,
  CMODELGEN_STATEMENT_CASEX,
  CMODELGEN_STATEMENT_CASE,
  CMODELGEN_STATEMENT_COND,
  CMODELGEN_STATEMENT_REPEAT,
  CMODELGEN_STATEMENT_WHILE,
  CMODELGEN_STATEMENT_NB_ASSIGN,
  CMODELGEN_STATEMENT_ASSIGN,
  CMODELGEN_STATEMENT_STASK,
  CMODELGEN_STATEMENT_UTASK,
  CMODELGEN_STATEMENT_ALLOC,
  CMODELGEN_STATEMENT_FREE,
  CMODELGEN_STATEMENT_WAIT,
  CMODELGEN_STATEMENT_DISABLE,
  CMODELGEN_STATEMENT_NOP
};

enum typVector
{
  CMODELGEN_VECTOR_SCALAR,
  CMODELGEN_VECTOR_VECTOR,
  CMODELGEN_VECTOR_VIRTUAL_VECTOR
};

enum typPort
{
  CMODELGEN_PORT_IN,
  CMODELGEN_PORT_OUT,
  CMODELGEN_PORT_INOUT,
  CMODELGEN_PORT_NONE
};

enum typCond
{
  CMODELGEN_COND_ANY,
  CMODELGEN_COND_ANYASSIGN,
  CMODELGEN_COND_POSEDGE,
  CMODELGEN_COND_NEGEDGE,
  CMODELGEN_COND_SIGNAL
};

enum typEvent
{
  CMODELGEN_EVENT_EVALUATION,
  CMODELGEN_EVENT_SUBEVENT,
  CMODELGEN_EVENT_NB_UPDATE,
  CMODELGEN_EVENT_LOGIC,
  CMODELGEN_EVENT_LPM,
  CMODELGEN_EVENT_MONITOR,
  CMODELGEN_EVENT_GROUP,
  CMODELGEN_EVENT_NONE
};

#endif // TYPE_H
