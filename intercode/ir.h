#ifndef _IR_H_
#define _IR_H_

#include<stdarg.h>
#include<stdio.h>
#include<stdlib.h>

//操作数
typedef struct Operand_* Operand;
struct Operand_{
    //操作数类别
    enum{VARIABLE, CONSTANT, ADDRESS, TMPVAR, LABEL} kind;
    
    //变量编号
    union{
        STE *ste;
        long int_value;
        double float_value;
        STE *addr;
        int tmpnum;
        int labelnum;
    }u;

    Operand pre,nxt;
};


//中间代码的类别，赋值，加减乘除，标签...
enum Kind{ 
    ASSIGNIR = 0, 
    ADDIR, SUBIR, MULIR, DIVIR, 
    LABELIR, GOTOIR, CONDJMPIR,
    READIR, WRITEIR, CALLIR, ARGIR, RETURNIR,
    DECIR, FUNIR, PARAIR
};
//中间代码的表示方式，我选择三地址代码
//IRhead代表中间代码链的头部
struct InterCode{
    enum Kind kind;
    union {
        struct {Operand lhs,rhs;} assign;
        struct {Operand res, op1, op2;} binop;
        Operand label;
        Operand gotolabel;
        struct {
            Operand lhs, rhs, label; 
            enum{G = 0, GE, EQ, L, LE, NE} relop;
        } cjmp;
        Operand read;
        Operand write;
        struct{ Operand res; STE *fun;}call;
        Operand arg;
        Operand ret;
        struct{STE *name; Operand size;}dec;
        STE *fun;
        STE *para;
    }u;

    struct InterCode *pre, *nxt;
} IRhead;




struct InterCode *newInterCodes(int kind, ...);

struct Operand_ *newOperand(int kind, ...);



void IRProgram0(struct GTNode *node);
void IRProgram1(struct GTNode *node);

void IRExtDefList0(struct GTNode *node);
void IRExtDefList1(struct GTNode *node);
void IRExtDefList2(struct GTNode *node);

void IRExtDef0(struct GTNode *node);
void IRExtDef1(struct GTNode *node);
void IRExtDef2(struct GTNode *node);
void IRExtDef3(struct GTNode *node);
void IRExtDef4(struct GTNode *node);

void IRExtDecList0(struct GTNode *node);
void IRExtDecList1(struct GTNode *node);
void IRExtDecList2(struct GTNode *node);


/*
void IRSpecifier0(struct GTNode *node);
void IRSpecifier1(struct GTNode *node);
void IRSpecifier2(struct GTNode *node);


void IRStructSpecifier0(struct GTNode *node);
void IRStructSpecifier1(struct GTNode *node);
void IRStructSpecifier2(struct GTNode *node);


void IROptTag0(struct GTNode *node);
void IROptTag1(struct GTNode *node);
void IROptTag2(struct GTNode *node);

void IRTag0(struct GTNode *node);
void IRTag1(struct GTNode *node);
*/

void IRVarDec0(struct GTNode *node, int mode);
void IRVarDec1(struct GTNode *node, int mode);
void IRVarDec2(struct GTNode *node, int mode);


void IRFunDec0(struct GTNode *node);
void IRFunDec1(struct GTNode *node);
void IRFunDec2(struct GTNode *node);


void IRVarList0(struct GTNode *node);
void IRVarList1(struct GTNode *node);
void IRVarList2(struct GTNode *node);

void IRParamDec0(struct GTNode *node);
void IRParamDec1(struct GTNode *node);

void IRCompSt0(struct GTNode *node);
void IRCompSt1(struct GTNode *node);

void IRStmtList0(struct GTNode *node);
void IRStmtList1(struct GTNode *node);
void IRStmtList2(struct GTNode *node);


void IRStmt0(struct GTNode *node);
void IRStmt1(struct GTNode *node);
void IRStmt2(struct GTNode *node);
void IRStmt3(struct GTNode *node);
void IRStmt4(struct GTNode *node);
void IRStmt5(struct GTNode *node);
void IRStmt6(struct GTNode *node);


void IRDefList0(struct GTNode *node);
void IRDefList1(struct GTNode *node);
void IRDefList2(struct GTNode *node);


void IRDef0(struct GTNode *node);
void IRDef1(struct GTNode *node);


void IRDecList0(struct GTNode *node);
void IRDecList1(struct GTNode *node);
void IRDecList2(struct GTNode *node);

void IRDec0(struct GTNode *node);
void IRDec1(struct GTNode *node);
void IRDec2(struct GTNode *node);


Type IRExp0(struct GTNode *node, Operand place);
void IRExp1(struct GTNode *node, Operand place);
void IRExp2(struct GTNode *node, Operand place);
void IRExp3(struct GTNode *node, Operand place);
void IRExp4(struct GTNode *node, Operand place);
void IRExp5(struct GTNode *node, Operand place);
void IRExp6(struct GTNode *node, Operand place);
void IRExp7(struct GTNode *node, Operand place);
void IRExp8(struct GTNode *node, Operand place);
void IRExp9(struct GTNode *node, Operand place);
void IRExp10(struct GTNode *node, Operand place);
void IRExp11(struct GTNode *node, Operand place);
void IRExp12(struct GTNode *node, Operand place);
void IRExp13(struct GTNode *node, Operand place);
Type IRExp14(struct GTNode *node, Operand place);
void IRExp15(struct GTNode *node);
Type IRExp16(struct GTNode *node, Operand place);
void IRExp17(struct GTNode *node, Operand place);
void IRExp18(struct GTNode *node, Operand place);

void IRArgs0(struct GTNode *node, Operand *arglist);
void IRArgs1(struct GTNode *node, Operand *arglist);
void IRArgs2(struct GTNode *node, Operand *arglist);



void translate_Cond(struct GTNode *node, Operand label_true, Operand label_false);




#endif