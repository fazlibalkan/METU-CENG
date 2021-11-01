/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0xcb73ee62 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif
static const char *ng0 = "Time=%.2d | K=%b B=%b| Q=%b";
static const char *ng1 = "D:/CENG/2-2/CENG232/lab3/lab3_part1/testbench_kb.v";
static int ng2[] = {0, 0};
static unsigned int ng3[] = {0U, 0U};
static const char *ng4 = "Initial value of Q is wrong";
static const char *ng5 = "Successful";
static unsigned int ng6[] = {1U, 0U};
static const char *ng7 = "Value of Q after Qprev=0 K=0 B=0 is wrong";
static const char *ng8 = "Value of Q after Qprev=1 K=0 B=0 is wrong";
static const char *ng9 = "Value of Q after Qprev=0 K=0 B=1 is wrong";
static const char *ng10 = "Value of Q after Qprev=0 K=1 B=0 is wrong";
static const char *ng11 = "Value of Q after Qprev=1 K=1 B=0 is wrong";
static const char *ng12 = "Value of Q after Qprev=1 K=1 B=1 is wrong";

void Monitor_27_3(char *);
void Monitor_27_3(char *);


static void Monitor_27_3_Func(char *t0)
{
    char t1[16];
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t2 = xsi_vlog_time(t1, 1000.0000000000000, 1000.0000000000000);
    t3 = (t0 + 828);
    t4 = (t3 + 36U);
    t5 = *((char **)t4);
    t6 = (t0 + 920);
    t7 = (t6 + 36U);
    t8 = *((char **)t7);
    t9 = (t0 + 600U);
    t10 = *((char **)t9);
    xsi_vlogfile_write(1, 0, 3, ng0, 5, t0, (char)118, t1, 64, (char)118, t5, 1, (char)118, t8, 1, (char)118, t10, 1);

LAB1:    return;
}

static void Initial_22_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(22, ng1);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 1012);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_23_1(char *t0)
{
    char t3[8];
    char *t1;
    char *t2;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    char *t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    char *t24;

LAB0:    t1 = (t0 + 1680U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(23, ng1);
    t2 = (t0 + 1580);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(23, ng1);
    t4 = (t0 + 1012);
    t5 = (t4 + 36U);
    t6 = *((char **)t5);
    memset(t3, 0, 8);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB8;

LAB6:    if (*((unsigned int *)t7) == 0)
        goto LAB5;

LAB7:    t13 = (t3 + 4);
    *((unsigned int *)t3) = 1;
    *((unsigned int *)t13) = 1;

LAB8:    t14 = (t3 + 4);
    t15 = (t6 + 4);
    t16 = *((unsigned int *)t6);
    t17 = (~(t16));
    *((unsigned int *)t3) = t17;
    *((unsigned int *)t14) = 0;
    if (*((unsigned int *)t15) != 0)
        goto LAB10;

LAB9:    t22 = *((unsigned int *)t3);
    *((unsigned int *)t3) = (t22 & 1U);
    t23 = *((unsigned int *)t14);
    *((unsigned int *)t14) = (t23 & 1U);
    t24 = (t0 + 1012);
    xsi_vlogvar_assign_value(t24, t3, 0, 0, 1);
    goto LAB2;

LAB5:    *((unsigned int *)t3) = 1;
    goto LAB8;

LAB10:    t18 = *((unsigned int *)t3);
    t19 = *((unsigned int *)t15);
    *((unsigned int *)t3) = (t18 | t19);
    t20 = *((unsigned int *)t14);
    t21 = *((unsigned int *)t15);
    *((unsigned int *)t14) = (t20 | t21);
    goto LAB9;

}

static void Initial_25_2(char *t0)
{
    char t4[8];
    char *t1;
    char *t2;
    char *t3;
    char *t5;
    char *t6;
    unsigned int t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    unsigned int t13;
    unsigned int t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    char *t19;
    char *t20;
    unsigned int t21;
    unsigned int t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;

LAB0:    t1 = (t0 + 1824U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng1);

LAB4:    xsi_set_current_line(27, ng1);
    Monitor_27_3(t0);
    xsi_set_current_line(30, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB5;

LAB1:    return;
LAB5:    xsi_set_current_line(31, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB7;

LAB6:    if (t16 != 0)
        goto LAB8;

LAB9:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB10;

LAB11:    xsi_set_current_line(32, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB12:    xsi_set_current_line(34, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB13;
    goto LAB1;

LAB7:    *((unsigned int *)t4) = 1;
    goto LAB9;

LAB8:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(31, ng1);
    xsi_vlogfile_write(1, 0, 0, ng4, 1, t0);
    goto LAB12;

LAB13:    xsi_set_current_line(35, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(35, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(37, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB14;
    goto LAB1;

LAB14:    xsi_set_current_line(38, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB16;

LAB15:    if (t16 != 0)
        goto LAB17;

LAB18:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB19;

LAB20:    xsi_set_current_line(39, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB21:    xsi_set_current_line(41, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB22;
    goto LAB1;

LAB16:    *((unsigned int *)t4) = 1;
    goto LAB18;

LAB17:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB18;

LAB19:    xsi_set_current_line(38, ng1);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    goto LAB21;

LAB22:    xsi_set_current_line(42, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB24;

LAB23:    if (t16 != 0)
        goto LAB25;

LAB26:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB27;

LAB28:    xsi_set_current_line(43, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB29:    xsi_set_current_line(45, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB30;
    goto LAB1;

LAB24:    *((unsigned int *)t4) = 1;
    goto LAB26;

LAB25:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB26;

LAB27:    xsi_set_current_line(42, ng1);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);
    goto LAB29;

LAB30:    xsi_set_current_line(46, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(46, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(48, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 9000LL);
    *((char **)t1) = &&LAB31;
    goto LAB1;

LAB31:    xsi_set_current_line(49, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB33;

LAB32:    if (t16 != 0)
        goto LAB34;

LAB35:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB36;

LAB37:    xsi_set_current_line(50, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB38:    xsi_set_current_line(52, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB39;
    goto LAB1;

LAB33:    *((unsigned int *)t4) = 1;
    goto LAB35;

LAB34:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB35;

LAB36:    xsi_set_current_line(49, ng1);
    xsi_vlogfile_write(1, 0, 0, ng9, 1, t0);
    goto LAB38;

LAB39:    xsi_set_current_line(53, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(53, ng1);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(55, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 9000LL);
    *((char **)t1) = &&LAB40;
    goto LAB1;

LAB40:    xsi_set_current_line(56, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB42;

LAB41:    if (t16 != 0)
        goto LAB43;

LAB44:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB45;

LAB46:    xsi_set_current_line(57, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB47:    xsi_set_current_line(59, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB48;
    goto LAB1;

LAB42:    *((unsigned int *)t4) = 1;
    goto LAB44;

LAB43:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB44;

LAB45:    xsi_set_current_line(56, ng1);
    xsi_vlogfile_write(1, 0, 0, ng10, 1, t0);
    goto LAB47;

LAB48:    xsi_set_current_line(60, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB50;

LAB49:    if (t16 != 0)
        goto LAB51;

LAB52:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(61, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB55:    xsi_set_current_line(63, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 1000LL);
    *((char **)t1) = &&LAB56;
    goto LAB1;

LAB50:    *((unsigned int *)t4) = 1;
    goto LAB52;

LAB51:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB52;

LAB53:    xsi_set_current_line(60, ng1);
    xsi_vlogfile_write(1, 0, 0, ng11, 1, t0);
    goto LAB55;

LAB56:    xsi_set_current_line(64, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 828);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(64, ng1);
    t2 = ((char*)((ng6)));
    t3 = (t0 + 920);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(66, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 9000LL);
    *((char **)t1) = &&LAB57;
    goto LAB1;

LAB57:    xsi_set_current_line(67, ng1);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t4, 0, 8);
    t5 = (t3 + 4);
    t6 = (t2 + 4);
    t7 = *((unsigned int *)t3);
    t8 = *((unsigned int *)t2);
    t9 = (t7 ^ t8);
    t10 = *((unsigned int *)t5);
    t11 = *((unsigned int *)t6);
    t12 = (t10 ^ t11);
    t13 = (t9 | t12);
    t14 = *((unsigned int *)t5);
    t15 = *((unsigned int *)t6);
    t16 = (t14 | t15);
    t17 = (~(t16));
    t18 = (t13 & t17);
    if (t18 != 0)
        goto LAB59;

LAB58:    if (t16 != 0)
        goto LAB60;

LAB61:    t20 = (t4 + 4);
    t21 = *((unsigned int *)t20);
    t22 = (~(t21));
    t23 = *((unsigned int *)t4);
    t24 = (t23 & t22);
    t25 = (t24 != 0);
    if (t25 > 0)
        goto LAB62;

LAB63:    xsi_set_current_line(68, ng1);
    xsi_vlogfile_write(1, 0, 0, ng5, 1, t0);

LAB64:    xsi_set_current_line(69, ng1);
    t2 = (t0 + 1724);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB65;
    goto LAB1;

LAB59:    *((unsigned int *)t4) = 1;
    goto LAB61;

LAB60:    t19 = (t4 + 4);
    *((unsigned int *)t4) = 1;
    *((unsigned int *)t19) = 1;
    goto LAB61;

LAB62:    xsi_set_current_line(67, ng1);
    xsi_vlogfile_write(1, 0, 0, ng12, 1, t0);
    goto LAB64;

LAB65:    xsi_set_current_line(70, ng1);
    xsi_vlog_finish(1);
    goto LAB1;

}

void Monitor_27_3(char *t0)
{
    char *t1;
    char *t2;

LAB0:    t1 = (t0 + 1868);
    t2 = (t0 + 2164);
    xsi_vlogfile_monitor((void *)Monitor_27_3_Func, t1, t2);

LAB1:    return;
}


extern void work_m_00000000002195686205_2820653688_init()
{
	static char *pe[] = {(void *)Initial_22_0,(void *)Always_23_1,(void *)Initial_25_2,(void *)Monitor_27_3};
	xsi_register_didat("work_m_00000000002195686205_2820653688", "isim/testbench_kb_isim_beh.exe.sim/work/m_00000000002195686205_2820653688.didat");
	xsi_register_executes(pe);
}
