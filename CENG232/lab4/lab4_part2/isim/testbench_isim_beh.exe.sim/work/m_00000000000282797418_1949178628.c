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
static const char *ng0 = "D:/CENG/2-2/CENG232/lab4/lab4_part2/testbench.v";
static int ng1[] = {0, 0};
static int ng2[] = {15, 0};
static int ng3[] = {1, 0};
static int ng4[] = {2, 0};
static int ng5[] = {11, 0};
static int ng6[] = {7, 0};
static const char *ng7 = "Case 0: Successfull!";
static const char *ng8 = "Case 0: Failure!";
static unsigned int ng9[] = {1U, 0U};
static unsigned int ng10[] = {7U, 3U};
static int ng11[] = {5, 0};
static const char *ng12 = "Case %2d: Successfull!";
static const char *ng13 = "Case %2d: Failure!";
static unsigned int ng14[] = {0U, 0U};
static int ng15[] = {10, 0};
static int ng16[] = {3, 0};
static int ng17[] = {55, 0};
static const char *ng18 = "Case 4: Successfull!";
static const char *ng19 = "Case 4: Failure!";
static const char *ng20 = "Case 5: Successfull!";
static const char *ng21 = "Case 5: Failure!";
static int ng22[] = {65, 0};
static const char *ng23 = "Case 6: Successfull!";
static const char *ng24 = "Case 6: Failure!";
static int ng25[] = {25, 0};
static const char *ng26 = "Case 7: Successfull!";
static const char *ng27 = "Case 7: Failure!";
static const char *ng28 = "Case 8: Successfull!";
static const char *ng29 = "Case 8: Failure!";
static const char *ng30 = "Case 9: Successfull!";
static const char *ng31 = "Case 9: Failure!";
static int ng32[] = {8, 0};
static int ng33[] = {9, 0};
static const char *ng34 = "Case 10: Successfull!";
static const char *ng35 = "Case 10: Failure!";
static const char *ng36 = "Time= %2d:%2d:%2d, PM: %2d, Remaining Time: %2d, Green for A: %2d, Green for B: %2d, Number of Cars on RoadA: %2d, Number of Cars on RoadB: %2d, BlackList Display: %2d ";



static void Initial_47_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(47, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 2024);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_48_1(char *t0)
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

LAB0:    t1 = (t0 + 2784U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(48, ng0);
    t2 = (t0 + 2684);
    xsi_process_wait(t2, 5000LL);
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(48, ng0);
    t4 = (t0 + 2024);
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
    t24 = (t0 + 2024);
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

static void Initial_51_2(char *t0)
{
    char t6[8];
    char t24[8];
    char t31[8];
    char t33[8];
    char t36[8];
    char t49[8];
    char t51[8];
    char t120[8];
    char t128[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    unsigned int t8;
    unsigned int t9;
    unsigned int t10;
    unsigned int t11;
    unsigned int t12;
    char *t13;
    char *t14;
    unsigned int t15;
    unsigned int t16;
    unsigned int t17;
    unsigned int t18;
    unsigned int t19;
    unsigned int t20;
    unsigned int t21;
    unsigned int t22;
    char *t23;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    unsigned int t28;
    char *t29;
    char *t30;
    char *t32;
    char *t34;
    char *t35;
    char *t37;
    char *t38;
    char *t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    char *t47;
    char *t48;
    char *t50;
    unsigned int t52;
    unsigned int t53;
    unsigned int t54;
    unsigned int t55;
    unsigned int t56;
    unsigned int t57;
    unsigned int t58;
    unsigned int t59;
    unsigned int t60;
    unsigned int t61;
    unsigned int t62;
    unsigned int t63;
    unsigned int t64;
    unsigned int t65;
    unsigned int t66;
    unsigned int t67;
    unsigned int t68;
    unsigned int t69;
    unsigned int t70;
    unsigned int t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    unsigned int t75;
    unsigned int t76;
    unsigned int t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    unsigned int t83;
    unsigned int t84;
    int t85;
    int t86;
    unsigned int t87;
    unsigned int t88;
    unsigned int t89;
    unsigned int t90;
    unsigned int t91;
    unsigned int t92;
    unsigned int t93;
    unsigned int t94;
    unsigned int t95;
    unsigned int t96;
    unsigned int t97;
    char *t98;
    char *t99;
    unsigned int t100;
    unsigned int t101;
    unsigned int t102;
    char *t103;
    char *t104;
    char *t105;
    char *t106;
    unsigned int t107;
    unsigned int t108;
    unsigned int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    unsigned int t116;
    unsigned int t117;
    unsigned int t118;
    char *t119;
    char *t121;
    unsigned int t122;
    unsigned int t123;
    unsigned int t124;
    unsigned int t125;
    unsigned int t126;
    char *t127;
    unsigned int t129;
    unsigned int t130;
    unsigned int t131;
    char *t132;
    char *t133;
    char *t134;
    unsigned int t135;
    unsigned int t136;
    unsigned int t137;
    unsigned int t138;
    unsigned int t139;
    unsigned int t140;
    unsigned int t141;
    char *t142;
    char *t143;
    unsigned int t144;
    unsigned int t145;
    unsigned int t146;
    unsigned int t147;
    unsigned int t148;
    unsigned int t149;
    unsigned int t150;
    unsigned int t151;
    int t152;
    int t153;
    unsigned int t154;
    unsigned int t155;
    unsigned int t156;
    unsigned int t157;
    unsigned int t158;
    unsigned int t159;
    char *t160;
    unsigned int t161;
    unsigned int t162;
    unsigned int t163;
    unsigned int t164;
    unsigned int t165;

LAB0:    t1 = (t0 + 2928U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(51, ng0);

LAB4:    xsi_set_current_line(52, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(53, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(54, ng0);
    xsi_set_current_line(54, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB5:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng2)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB6;

LAB7:    xsi_set_current_line(64, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(65, ng0);
    t2 = (t0 + 1336U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng6)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB22;

LAB19:    if (t19 != 0)
        goto LAB21;

LAB20:    *((unsigned int *)t6) = 1;

LAB22:    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB23;

LAB24:    xsi_set_current_line(68, ng0);
    xsi_vlogfile_write(1, 0, 0, ng8, 1, t0);

LAB25:    xsi_set_current_line(69, ng0);

LAB26:    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB30;

LAB27:    if (t19 != 0)
        goto LAB29;

LAB28:    *((unsigned int *)t6) = 1;

LAB30:    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB31;

LAB32:    xsi_set_current_line(75, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(76, ng0);
    xsi_set_current_line(76, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB41:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng11)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB42;

LAB43:    xsi_set_current_line(87, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(88, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(90, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB57;

LAB1:    return;
LAB6:    xsi_set_current_line(55, ng0);

LAB8:    xsi_set_current_line(56, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 20000LL);
    *((char **)t1) = &&LAB9;
    goto LAB1;

LAB9:    xsi_set_current_line(57, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB13;

LAB11:    if (*((unsigned int *)t5) == 0)
        goto LAB10;

LAB12:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB13:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB15;

LAB14:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(58, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 1840);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(59, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_mod(t6, 32, t4, 32, t5, 32);
    t7 = ((char*)((ng1)));
    memset(t24, 0, 8);
    xsi_vlog_signed_equal(t24, 32, t6, 32, t7, 32);
    t13 = (t24 + 4);
    t8 = *((unsigned int *)t13);
    t9 = (~(t8));
    t10 = *((unsigned int *)t24);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB16;

LAB17:    xsi_set_current_line(62, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);

LAB18:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB5;

LAB10:    *((unsigned int *)t6) = 1;
    goto LAB13;

LAB15:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB14;

LAB16:    xsi_set_current_line(60, ng0);
    t14 = ((char*)((ng5)));
    t23 = (t0 + 1748);
    xsi_vlogvar_assign_value(t23, t14, 0, 0, 3);
    goto LAB18;

LAB21:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB22;

LAB23:    xsi_set_current_line(66, ng0);
    xsi_vlogfile_write(1, 0, 0, ng7, 1, t0);
    goto LAB25;

LAB29:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB30;

LAB31:    xsi_set_current_line(70, ng0);

LAB33:    xsi_set_current_line(71, ng0);
    t14 = (t0 + 2828);
    xsi_process_wait(t14, 10000LL);
    *((char **)t1) = &&LAB34;
    goto LAB1;

LAB34:    xsi_set_current_line(72, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB38;

LAB36:    if (*((unsigned int *)t5) == 0)
        goto LAB35;

LAB37:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB38:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB40;

LAB39:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(73, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    goto LAB26;

LAB35:    *((unsigned int *)t6) = 1;
    goto LAB38;

LAB40:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB39;

LAB42:    xsi_set_current_line(77, ng0);

LAB44:    xsi_set_current_line(78, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB45;
    goto LAB1;

LAB45:    xsi_set_current_line(79, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_mod(t6, 32, t4, 32, t5, 32);
    t7 = ((char*)((ng1)));
    memset(t24, 0, 8);
    xsi_vlog_signed_equal(t24, 32, t6, 32, t7, 32);
    t13 = (t24 + 4);
    t8 = *((unsigned int *)t13);
    t9 = (~(t8));
    t10 = *((unsigned int *)t24);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB46;

LAB47:
LAB48:    xsi_set_current_line(76, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB41;

LAB46:    xsi_set_current_line(80, ng0);

LAB49:    xsi_set_current_line(81, ng0);
    t14 = (t0 + 2116);
    t23 = (t14 + 36U);
    t29 = *((char **)t23);
    t30 = ((char*)((ng4)));
    memset(t31, 0, 8);
    xsi_vlog_unsigned_multiply(t31, 32, t29, 32, t30, 32);
    t32 = ((char*)((ng3)));
    memset(t33, 0, 8);
    xsi_vlog_unsigned_add(t33, 32, t31, 32, t32, 32);
    t34 = (t0 + 1520U);
    t35 = *((char **)t34);
    memset(t36, 0, 8);
    t34 = (t33 + 4);
    t37 = (t35 + 4);
    t15 = *((unsigned int *)t33);
    t16 = *((unsigned int *)t35);
    t17 = (t15 ^ t16);
    t18 = *((unsigned int *)t34);
    t19 = *((unsigned int *)t37);
    t20 = (t18 ^ t19);
    t21 = (t17 | t20);
    t22 = *((unsigned int *)t34);
    t25 = *((unsigned int *)t37);
    t26 = (t22 | t25);
    t27 = (~(t26));
    t28 = (t21 & t27);
    if (t28 != 0)
        goto LAB53;

LAB50:    if (t26 != 0)
        goto LAB52;

LAB51:    *((unsigned int *)t36) = 1;

LAB53:    t39 = (t36 + 4);
    t40 = *((unsigned int *)t39);
    t41 = (~(t40));
    t42 = *((unsigned int *)t36);
    t43 = (t42 & t41);
    t44 = (t43 != 0);
    if (t44 > 0)
        goto LAB54;

LAB55:    xsi_set_current_line(84, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_divide(t6, 32, t4, 32, t5, 32);
    t7 = ((char*)((ng3)));
    memset(t24, 0, 8);
    xsi_vlog_signed_add(t24, 32, t6, 32, t7, 32);
    xsi_vlogfile_write(1, 0, 0, ng13, 2, t0, (char)119, t24, 32);

LAB56:    goto LAB48;

LAB52:    t38 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB53;

LAB54:    xsi_set_current_line(82, ng0);
    t45 = (t0 + 2116);
    t46 = (t45 + 36U);
    t47 = *((char **)t46);
    t48 = ((char*)((ng4)));
    memset(t49, 0, 8);
    xsi_vlog_signed_divide(t49, 32, t47, 32, t48, 32);
    t50 = ((char*)((ng3)));
    memset(t51, 0, 8);
    xsi_vlog_signed_add(t51, 32, t49, 32, t50, 32);
    xsi_vlogfile_write(1, 0, 0, ng12, 2, t0, (char)119, t51, 32);
    goto LAB56;

LAB57:    xsi_set_current_line(91, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(92, ng0);
    xsi_set_current_line(92, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB58:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng6)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB59;

LAB60:    xsi_set_current_line(98, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(99, ng0);
    t2 = ((char*)((ng14)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(100, ng0);

LAB69:    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB73;

LAB70:    if (t19 != 0)
        goto LAB72;

LAB71:    *((unsigned int *)t6) = 1;

LAB73:    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB74;

LAB75:    xsi_set_current_line(104, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB77;
    goto LAB1;

LAB59:    xsi_set_current_line(93, ng0);

LAB61:    xsi_set_current_line(94, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB62;
    goto LAB1;

LAB62:    xsi_set_current_line(95, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_multiply(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 1840);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(96, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB66;

LAB64:    if (*((unsigned int *)t5) == 0)
        goto LAB63;

LAB65:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB66:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB68;

LAB67:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(92, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB58;

LAB63:    *((unsigned int *)t6) = 1;
    goto LAB66;

LAB68:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB67;

LAB72:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB73;

LAB74:    xsi_set_current_line(101, ng0);
    t14 = (t0 + 2828);
    xsi_process_wait(t14, 10000LL);
    *((char **)t1) = &&LAB76;
    goto LAB1;

LAB76:    goto LAB69;

LAB77:    xsi_set_current_line(107, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB81;

LAB78:    if (t19 != 0)
        goto LAB80;

LAB79:    *((unsigned int *)t6) = 1;

LAB81:    memset(t24, 0, 8);
    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB82;

LAB83:    if (*((unsigned int *)t13) != 0)
        goto LAB84;

LAB85:    t23 = (t24 + 4);
    t40 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t23);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB86;

LAB87:    memcpy(t36, t24, 8);

LAB88:    memset(t49, 0, 8);
    t50 = (t36 + 4);
    t93 = *((unsigned int *)t50);
    t94 = (~(t93));
    t95 = *((unsigned int *)t36);
    t96 = (t95 & t94);
    t97 = (t96 & 1U);
    if (t97 != 0)
        goto LAB100;

LAB101:    if (*((unsigned int *)t50) != 0)
        goto LAB102;

LAB103:    t99 = (t49 + 4);
    t100 = *((unsigned int *)t49);
    t101 = *((unsigned int *)t99);
    t102 = (t100 || t101);
    if (t102 > 0)
        goto LAB104;

LAB105:    memcpy(t128, t49, 8);

LAB106:    t160 = (t128 + 4);
    t161 = *((unsigned int *)t160);
    t162 = (~(t161));
    t163 = *((unsigned int *)t128);
    t164 = (t163 & t162);
    t165 = (t164 != 0);
    if (t165 > 0)
        goto LAB118;

LAB119:    xsi_set_current_line(110, ng0);
    xsi_vlogfile_write(1, 0, 0, ng19, 1, t0);

LAB120:    xsi_set_current_line(111, ng0);

LAB121:    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB125;

LAB122:    if (t19 != 0)
        goto LAB124;

LAB123:    *((unsigned int *)t6) = 1;

LAB125:    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB126;

LAB127:    xsi_set_current_line(117, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(118, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB139;

LAB136:    if (t19 != 0)
        goto LAB138;

LAB137:    *((unsigned int *)t6) = 1;

LAB139:    memset(t24, 0, 8);
    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB140;

LAB141:    if (*((unsigned int *)t13) != 0)
        goto LAB142;

LAB143:    t23 = (t24 + 4);
    t40 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t23);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB144;

LAB145:    memcpy(t36, t24, 8);

LAB146:    t50 = (t36 + 4);
    t93 = *((unsigned int *)t50);
    t94 = (~(t93));
    t95 = *((unsigned int *)t36);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB158;

LAB159:    xsi_set_current_line(121, ng0);
    xsi_vlogfile_write(1, 0, 0, ng21, 1, t0);

LAB160:    xsi_set_current_line(123, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 36000000LL);
    *((char **)t1) = &&LAB161;
    goto LAB1;

LAB80:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB81;

LAB82:    *((unsigned int *)t24) = 1;
    goto LAB85;

LAB84:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB85;

LAB86:    t29 = (t0 + 1244U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng16)));
    memset(t31, 0, 8);
    t32 = (t30 + 4);
    t34 = (t29 + 4);
    t43 = *((unsigned int *)t30);
    t44 = *((unsigned int *)t29);
    t52 = (t43 ^ t44);
    t53 = *((unsigned int *)t32);
    t54 = *((unsigned int *)t34);
    t55 = (t53 ^ t54);
    t56 = (t52 | t55);
    t57 = *((unsigned int *)t32);
    t58 = *((unsigned int *)t34);
    t59 = (t57 | t58);
    t60 = (~(t59));
    t61 = (t56 & t60);
    if (t61 != 0)
        goto LAB92;

LAB89:    if (t59 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t31) = 1;

LAB92:    memset(t33, 0, 8);
    t37 = (t31 + 4);
    t62 = *((unsigned int *)t37);
    t63 = (~(t62));
    t64 = *((unsigned int *)t31);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB93;

LAB94:    if (*((unsigned int *)t37) != 0)
        goto LAB95;

LAB96:    t67 = *((unsigned int *)t24);
    t68 = *((unsigned int *)t33);
    t69 = (t67 & t68);
    *((unsigned int *)t36) = t69;
    t39 = (t24 + 4);
    t45 = (t33 + 4);
    t46 = (t36 + 4);
    t70 = *((unsigned int *)t39);
    t71 = *((unsigned int *)t45);
    t72 = (t70 | t71);
    *((unsigned int *)t46) = t72;
    t73 = *((unsigned int *)t46);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB97;

LAB98:
LAB99:    goto LAB88;

LAB91:    t35 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB92;

LAB93:    *((unsigned int *)t33) = 1;
    goto LAB96;

LAB95:    t38 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB96;

LAB97:    t75 = *((unsigned int *)t36);
    t76 = *((unsigned int *)t46);
    *((unsigned int *)t36) = (t75 | t76);
    t47 = (t24 + 4);
    t48 = (t33 + 4);
    t77 = *((unsigned int *)t24);
    t78 = (~(t77));
    t79 = *((unsigned int *)t47);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (~(t83));
    t85 = (t78 & t80);
    t86 = (t82 & t84);
    t87 = (~(t85));
    t88 = (~(t86));
    t89 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t89 & t87);
    t90 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t90 & t88);
    t91 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t91 & t87);
    t92 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t92 & t88);
    goto LAB99;

LAB100:    *((unsigned int *)t49) = 1;
    goto LAB103;

LAB102:    t98 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t98) = 1;
    goto LAB103;

LAB104:    t103 = (t0 + 1428U);
    t104 = *((char **)t103);
    t103 = ((char*)((ng17)));
    memset(t51, 0, 8);
    t105 = (t104 + 4);
    t106 = (t103 + 4);
    t107 = *((unsigned int *)t104);
    t108 = *((unsigned int *)t103);
    t109 = (t107 ^ t108);
    t110 = *((unsigned int *)t105);
    t111 = *((unsigned int *)t106);
    t112 = (t110 ^ t111);
    t113 = (t109 | t112);
    t114 = *((unsigned int *)t105);
    t115 = *((unsigned int *)t106);
    t116 = (t114 | t115);
    t117 = (~(t116));
    t118 = (t113 & t117);
    if (t118 != 0)
        goto LAB110;

LAB107:    if (t116 != 0)
        goto LAB109;

LAB108:    *((unsigned int *)t51) = 1;

LAB110:    memset(t120, 0, 8);
    t121 = (t51 + 4);
    t122 = *((unsigned int *)t121);
    t123 = (~(t122));
    t124 = *((unsigned int *)t51);
    t125 = (t124 & t123);
    t126 = (t125 & 1U);
    if (t126 != 0)
        goto LAB111;

LAB112:    if (*((unsigned int *)t121) != 0)
        goto LAB113;

LAB114:    t129 = *((unsigned int *)t49);
    t130 = *((unsigned int *)t120);
    t131 = (t129 & t130);
    *((unsigned int *)t128) = t131;
    t132 = (t49 + 4);
    t133 = (t120 + 4);
    t134 = (t128 + 4);
    t135 = *((unsigned int *)t132);
    t136 = *((unsigned int *)t133);
    t137 = (t135 | t136);
    *((unsigned int *)t134) = t137;
    t138 = *((unsigned int *)t134);
    t139 = (t138 != 0);
    if (t139 == 1)
        goto LAB115;

LAB116:
LAB117:    goto LAB106;

LAB109:    t119 = (t51 + 4);
    *((unsigned int *)t51) = 1;
    *((unsigned int *)t119) = 1;
    goto LAB110;

LAB111:    *((unsigned int *)t120) = 1;
    goto LAB114;

LAB113:    t127 = (t120 + 4);
    *((unsigned int *)t120) = 1;
    *((unsigned int *)t127) = 1;
    goto LAB114;

LAB115:    t140 = *((unsigned int *)t128);
    t141 = *((unsigned int *)t134);
    *((unsigned int *)t128) = (t140 | t141);
    t142 = (t49 + 4);
    t143 = (t120 + 4);
    t144 = *((unsigned int *)t49);
    t145 = (~(t144));
    t146 = *((unsigned int *)t142);
    t147 = (~(t146));
    t148 = *((unsigned int *)t120);
    t149 = (~(t148));
    t150 = *((unsigned int *)t143);
    t151 = (~(t150));
    t152 = (t145 & t147);
    t153 = (t149 & t151);
    t154 = (~(t152));
    t155 = (~(t153));
    t156 = *((unsigned int *)t134);
    *((unsigned int *)t134) = (t156 & t154);
    t157 = *((unsigned int *)t134);
    *((unsigned int *)t134) = (t157 & t155);
    t158 = *((unsigned int *)t128);
    *((unsigned int *)t128) = (t158 & t154);
    t159 = *((unsigned int *)t128);
    *((unsigned int *)t128) = (t159 & t155);
    goto LAB117;

LAB118:    xsi_set_current_line(108, ng0);
    xsi_vlogfile_write(1, 0, 0, ng18, 1, t0);
    goto LAB120;

LAB124:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB125;

LAB126:    xsi_set_current_line(112, ng0);

LAB128:    xsi_set_current_line(113, ng0);
    t14 = ((char*)((ng1)));
    t23 = (t0 + 1748);
    xsi_vlogvar_assign_value(t23, t14, 0, 0, 3);
    xsi_set_current_line(114, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB132;

LAB130:    if (*((unsigned int *)t5) == 0)
        goto LAB129;

LAB131:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB132:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB134;

LAB133:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(115, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB135;
    goto LAB1;

LAB129:    *((unsigned int *)t6) = 1;
    goto LAB132;

LAB134:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB133;

LAB135:    goto LAB121;

LAB138:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB139;

LAB140:    *((unsigned int *)t24) = 1;
    goto LAB143;

LAB142:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB143;

LAB144:    t29 = (t0 + 1244U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng1)));
    memset(t31, 0, 8);
    t32 = (t30 + 4);
    t34 = (t29 + 4);
    t43 = *((unsigned int *)t30);
    t44 = *((unsigned int *)t29);
    t52 = (t43 ^ t44);
    t53 = *((unsigned int *)t32);
    t54 = *((unsigned int *)t34);
    t55 = (t53 ^ t54);
    t56 = (t52 | t55);
    t57 = *((unsigned int *)t32);
    t58 = *((unsigned int *)t34);
    t59 = (t57 | t58);
    t60 = (~(t59));
    t61 = (t56 & t60);
    if (t61 != 0)
        goto LAB150;

LAB147:    if (t59 != 0)
        goto LAB149;

LAB148:    *((unsigned int *)t31) = 1;

LAB150:    memset(t33, 0, 8);
    t37 = (t31 + 4);
    t62 = *((unsigned int *)t37);
    t63 = (~(t62));
    t64 = *((unsigned int *)t31);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB151;

LAB152:    if (*((unsigned int *)t37) != 0)
        goto LAB153;

LAB154:    t67 = *((unsigned int *)t24);
    t68 = *((unsigned int *)t33);
    t69 = (t67 & t68);
    *((unsigned int *)t36) = t69;
    t39 = (t24 + 4);
    t45 = (t33 + 4);
    t46 = (t36 + 4);
    t70 = *((unsigned int *)t39);
    t71 = *((unsigned int *)t45);
    t72 = (t70 | t71);
    *((unsigned int *)t46) = t72;
    t73 = *((unsigned int *)t46);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB155;

LAB156:
LAB157:    goto LAB146;

LAB149:    t35 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB150;

LAB151:    *((unsigned int *)t33) = 1;
    goto LAB154;

LAB153:    t38 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB154;

LAB155:    t75 = *((unsigned int *)t36);
    t76 = *((unsigned int *)t46);
    *((unsigned int *)t36) = (t75 | t76);
    t47 = (t24 + 4);
    t48 = (t33 + 4);
    t77 = *((unsigned int *)t24);
    t78 = (~(t77));
    t79 = *((unsigned int *)t47);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (~(t83));
    t85 = (t78 & t80);
    t86 = (t82 & t84);
    t87 = (~(t85));
    t88 = (~(t86));
    t89 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t89 & t87);
    t90 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t90 & t88);
    t91 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t91 & t87);
    t92 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t92 & t88);
    goto LAB157;

LAB158:    xsi_set_current_line(119, ng0);
    xsi_vlogfile_write(1, 0, 0, ng20, 1, t0);
    goto LAB160;

LAB161:    xsi_set_current_line(125, ng0);
    t2 = (t0 + 1428U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng22)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB165;

LAB162:    if (t19 != 0)
        goto LAB164;

LAB163:    *((unsigned int *)t6) = 1;

LAB165:    memset(t24, 0, 8);
    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB166;

LAB167:    if (*((unsigned int *)t13) != 0)
        goto LAB168;

LAB169:    t23 = (t24 + 4);
    t40 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t23);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB170;

LAB171:    memcpy(t33, t24, 8);

LAB172:    memset(t36, 0, 8);
    t45 = (t33 + 4);
    t79 = *((unsigned int *)t45);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB180;

LAB181:    if (*((unsigned int *)t45) != 0)
        goto LAB182;

LAB183:    t47 = (t36 + 4);
    t84 = *((unsigned int *)t36);
    t87 = *((unsigned int *)t47);
    t88 = (t84 || t87);
    if (t88 > 0)
        goto LAB184;

LAB185:    memcpy(t51, t36, 8);

LAB186:    t119 = (t51 + 4);
    t129 = *((unsigned int *)t119);
    t130 = (~(t129));
    t131 = *((unsigned int *)t51);
    t135 = (t131 & t130);
    t136 = (t135 != 0);
    if (t136 > 0)
        goto LAB194;

LAB195:    xsi_set_current_line(128, ng0);
    xsi_vlogfile_write(1, 0, 0, ng24, 1, t0);

LAB196:    xsi_set_current_line(130, ng0);

LAB197:    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng9)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB201;

LAB198:    if (t19 != 0)
        goto LAB200;

LAB199:    *((unsigned int *)t6) = 1;

LAB201:    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 != 0);
    if (t28 > 0)
        goto LAB202;

LAB203:    xsi_set_current_line(133, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 3000000LL);
    *((char **)t1) = &&LAB205;
    goto LAB1;

LAB164:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB165;

LAB166:    *((unsigned int *)t24) = 1;
    goto LAB169;

LAB168:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB169;

LAB170:    t29 = (t0 + 784U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    t29 = (t30 + 4);
    t43 = *((unsigned int *)t29);
    t44 = (~(t43));
    t52 = *((unsigned int *)t30);
    t53 = (t52 & t44);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB173;

LAB174:    if (*((unsigned int *)t29) != 0)
        goto LAB175;

LAB176:    t55 = *((unsigned int *)t24);
    t56 = *((unsigned int *)t31);
    t57 = (t55 & t56);
    *((unsigned int *)t33) = t57;
    t34 = (t24 + 4);
    t35 = (t31 + 4);
    t37 = (t33 + 4);
    t58 = *((unsigned int *)t34);
    t59 = *((unsigned int *)t35);
    t60 = (t58 | t59);
    *((unsigned int *)t37) = t60;
    t61 = *((unsigned int *)t37);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB177;

LAB178:
LAB179:    goto LAB172;

LAB173:    *((unsigned int *)t31) = 1;
    goto LAB176;

LAB175:    t32 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB176;

LAB177:    t63 = *((unsigned int *)t33);
    t64 = *((unsigned int *)t37);
    *((unsigned int *)t33) = (t63 | t64);
    t38 = (t24 + 4);
    t39 = (t31 + 4);
    t65 = *((unsigned int *)t24);
    t66 = (~(t65));
    t67 = *((unsigned int *)t38);
    t68 = (~(t67));
    t69 = *((unsigned int *)t31);
    t70 = (~(t69));
    t71 = *((unsigned int *)t39);
    t72 = (~(t71));
    t85 = (t66 & t68);
    t86 = (t70 & t72);
    t73 = (~(t85));
    t74 = (~(t86));
    t75 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t75 & t73);
    t76 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t76 & t74);
    t77 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t77 & t73);
    t78 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t78 & t74);
    goto LAB179;

LAB180:    *((unsigned int *)t36) = 1;
    goto LAB183;

LAB182:    t46 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t46) = 1;
    goto LAB183;

LAB184:    t48 = (t0 + 600U);
    t50 = *((char **)t48);
    memset(t49, 0, 8);
    t48 = (t50 + 4);
    t89 = *((unsigned int *)t48);
    t90 = (~(t89));
    t91 = *((unsigned int *)t50);
    t92 = (t91 & t90);
    t93 = (t92 & 1U);
    if (t93 != 0)
        goto LAB187;

LAB188:    if (*((unsigned int *)t48) != 0)
        goto LAB189;

LAB190:    t94 = *((unsigned int *)t36);
    t95 = *((unsigned int *)t49);
    t96 = (t94 & t95);
    *((unsigned int *)t51) = t96;
    t99 = (t36 + 4);
    t103 = (t49 + 4);
    t104 = (t51 + 4);
    t97 = *((unsigned int *)t99);
    t100 = *((unsigned int *)t103);
    t101 = (t97 | t100);
    *((unsigned int *)t104) = t101;
    t102 = *((unsigned int *)t104);
    t107 = (t102 != 0);
    if (t107 == 1)
        goto LAB191;

LAB192:
LAB193:    goto LAB186;

LAB187:    *((unsigned int *)t49) = 1;
    goto LAB190;

LAB189:    t98 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t98) = 1;
    goto LAB190;

LAB191:    t108 = *((unsigned int *)t51);
    t109 = *((unsigned int *)t104);
    *((unsigned int *)t51) = (t108 | t109);
    t105 = (t36 + 4);
    t106 = (t49 + 4);
    t110 = *((unsigned int *)t36);
    t111 = (~(t110));
    t112 = *((unsigned int *)t105);
    t113 = (~(t112));
    t114 = *((unsigned int *)t49);
    t115 = (~(t114));
    t116 = *((unsigned int *)t106);
    t117 = (~(t116));
    t152 = (t111 & t113);
    t153 = (t115 & t117);
    t118 = (~(t152));
    t122 = (~(t153));
    t123 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t123 & t118);
    t124 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t124 & t122);
    t125 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t125 & t118);
    t126 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t126 & t122);
    goto LAB193;

LAB194:    xsi_set_current_line(126, ng0);
    xsi_vlogfile_write(1, 0, 0, ng23, 1, t0);
    goto LAB196;

LAB200:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB201;

LAB202:    xsi_set_current_line(131, ng0);
    t14 = (t0 + 2828);
    xsi_process_wait(t14, 10000LL);
    *((char **)t1) = &&LAB204;
    goto LAB1;

LAB204:    goto LAB197;

LAB205:    xsi_set_current_line(134, ng0);
    t2 = (t0 + 1428U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng25)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB209;

LAB206:    if (t19 != 0)
        goto LAB208;

LAB207:    *((unsigned int *)t6) = 1;

LAB209:    memset(t24, 0, 8);
    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB210;

LAB211:    if (*((unsigned int *)t13) != 0)
        goto LAB212;

LAB213:    t23 = (t24 + 4);
    t40 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t23);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB214;

LAB215:    memcpy(t33, t24, 8);

LAB216:    memset(t36, 0, 8);
    t45 = (t33 + 4);
    t79 = *((unsigned int *)t45);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t82 = (t81 & t80);
    t83 = (t82 & 1U);
    if (t83 != 0)
        goto LAB224;

LAB225:    if (*((unsigned int *)t45) != 0)
        goto LAB226;

LAB227:    t47 = (t36 + 4);
    t84 = *((unsigned int *)t36);
    t87 = *((unsigned int *)t47);
    t88 = (t84 || t87);
    if (t88 > 0)
        goto LAB228;

LAB229:    memcpy(t51, t36, 8);

LAB230:    t119 = (t51 + 4);
    t129 = *((unsigned int *)t119);
    t130 = (~(t129));
    t131 = *((unsigned int *)t51);
    t135 = (t131 & t130);
    t136 = (t135 != 0);
    if (t136 > 0)
        goto LAB238;

LAB239:    xsi_set_current_line(137, ng0);
    xsi_vlogfile_write(1, 0, 0, ng27, 1, t0);

LAB240:    xsi_set_current_line(139, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 66870000LL);
    *((char **)t1) = &&LAB241;
    goto LAB1;

LAB208:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB209;

LAB210:    *((unsigned int *)t24) = 1;
    goto LAB213;

LAB212:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB213;

LAB214:    t29 = (t0 + 692U);
    t30 = *((char **)t29);
    memset(t31, 0, 8);
    t29 = (t30 + 4);
    t43 = *((unsigned int *)t29);
    t44 = (~(t43));
    t52 = *((unsigned int *)t30);
    t53 = (t52 & t44);
    t54 = (t53 & 1U);
    if (t54 != 0)
        goto LAB217;

LAB218:    if (*((unsigned int *)t29) != 0)
        goto LAB219;

LAB220:    t55 = *((unsigned int *)t24);
    t56 = *((unsigned int *)t31);
    t57 = (t55 & t56);
    *((unsigned int *)t33) = t57;
    t34 = (t24 + 4);
    t35 = (t31 + 4);
    t37 = (t33 + 4);
    t58 = *((unsigned int *)t34);
    t59 = *((unsigned int *)t35);
    t60 = (t58 | t59);
    *((unsigned int *)t37) = t60;
    t61 = *((unsigned int *)t37);
    t62 = (t61 != 0);
    if (t62 == 1)
        goto LAB221;

LAB222:
LAB223:    goto LAB216;

LAB217:    *((unsigned int *)t31) = 1;
    goto LAB220;

LAB219:    t32 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t32) = 1;
    goto LAB220;

LAB221:    t63 = *((unsigned int *)t33);
    t64 = *((unsigned int *)t37);
    *((unsigned int *)t33) = (t63 | t64);
    t38 = (t24 + 4);
    t39 = (t31 + 4);
    t65 = *((unsigned int *)t24);
    t66 = (~(t65));
    t67 = *((unsigned int *)t38);
    t68 = (~(t67));
    t69 = *((unsigned int *)t31);
    t70 = (~(t69));
    t71 = *((unsigned int *)t39);
    t72 = (~(t71));
    t85 = (t66 & t68);
    t86 = (t70 & t72);
    t73 = (~(t85));
    t74 = (~(t86));
    t75 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t75 & t73);
    t76 = *((unsigned int *)t37);
    *((unsigned int *)t37) = (t76 & t74);
    t77 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t77 & t73);
    t78 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t78 & t74);
    goto LAB223;

LAB224:    *((unsigned int *)t36) = 1;
    goto LAB227;

LAB226:    t46 = (t36 + 4);
    *((unsigned int *)t36) = 1;
    *((unsigned int *)t46) = 1;
    goto LAB227;

LAB228:    t48 = (t0 + 784U);
    t50 = *((char **)t48);
    memset(t49, 0, 8);
    t48 = (t50 + 4);
    t89 = *((unsigned int *)t48);
    t90 = (~(t89));
    t91 = *((unsigned int *)t50);
    t92 = (t91 & t90);
    t93 = (t92 & 1U);
    if (t93 != 0)
        goto LAB231;

LAB232:    if (*((unsigned int *)t48) != 0)
        goto LAB233;

LAB234:    t94 = *((unsigned int *)t36);
    t95 = *((unsigned int *)t49);
    t96 = (t94 & t95);
    *((unsigned int *)t51) = t96;
    t99 = (t36 + 4);
    t103 = (t49 + 4);
    t104 = (t51 + 4);
    t97 = *((unsigned int *)t99);
    t100 = *((unsigned int *)t103);
    t101 = (t97 | t100);
    *((unsigned int *)t104) = t101;
    t102 = *((unsigned int *)t104);
    t107 = (t102 != 0);
    if (t107 == 1)
        goto LAB235;

LAB236:
LAB237:    goto LAB230;

LAB231:    *((unsigned int *)t49) = 1;
    goto LAB234;

LAB233:    t98 = (t49 + 4);
    *((unsigned int *)t49) = 1;
    *((unsigned int *)t98) = 1;
    goto LAB234;

LAB235:    t108 = *((unsigned int *)t51);
    t109 = *((unsigned int *)t104);
    *((unsigned int *)t51) = (t108 | t109);
    t105 = (t36 + 4);
    t106 = (t49 + 4);
    t110 = *((unsigned int *)t36);
    t111 = (~(t110));
    t112 = *((unsigned int *)t105);
    t113 = (~(t112));
    t114 = *((unsigned int *)t49);
    t115 = (~(t114));
    t116 = *((unsigned int *)t106);
    t117 = (~(t116));
    t152 = (t111 & t113);
    t153 = (t115 & t117);
    t118 = (~(t152));
    t122 = (~(t153));
    t123 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t123 & t118);
    t124 = *((unsigned int *)t104);
    *((unsigned int *)t104) = (t124 & t122);
    t125 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t125 & t118);
    t126 = *((unsigned int *)t51);
    *((unsigned int *)t51) = (t126 & t122);
    goto LAB237;

LAB238:    xsi_set_current_line(135, ng0);
    xsi_vlogfile_write(1, 0, 0, ng26, 1, t0);
    goto LAB240;

LAB241:    xsi_set_current_line(140, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB242;

LAB243:    if (*((unsigned int *)t2) != 0)
        goto LAB244;

LAB245:    t5 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t5);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB246;

LAB247:    memcpy(t31, t6, 8);

LAB248:    t35 = (t31 + 4);
    t67 = *((unsigned int *)t35);
    t68 = (~(t67));
    t69 = *((unsigned int *)t31);
    t70 = (t69 & t68);
    t71 = (t70 != 0);
    if (t71 > 0)
        goto LAB256;

LAB257:    xsi_set_current_line(143, ng0);
    xsi_vlogfile_write(1, 0, 0, ng29, 1, t0);

LAB258:    xsi_set_current_line(144, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB259;
    goto LAB1;

LAB242:    *((unsigned int *)t6) = 1;
    goto LAB245;

LAB244:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB245;

LAB246:    t7 = (t0 + 784U);
    t13 = *((char **)t7);
    memset(t24, 0, 8);
    t7 = (t13 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (~(t18));
    t20 = *((unsigned int *)t13);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB249;

LAB250:    if (*((unsigned int *)t7) != 0)
        goto LAB251;

LAB252:    t25 = *((unsigned int *)t6);
    t26 = *((unsigned int *)t24);
    t27 = (t25 & t26);
    *((unsigned int *)t31) = t27;
    t23 = (t6 + 4);
    t29 = (t24 + 4);
    t30 = (t31 + 4);
    t28 = *((unsigned int *)t23);
    t40 = *((unsigned int *)t29);
    t41 = (t28 | t40);
    *((unsigned int *)t30) = t41;
    t42 = *((unsigned int *)t30);
    t43 = (t42 != 0);
    if (t43 == 1)
        goto LAB253;

LAB254:
LAB255:    goto LAB248;

LAB249:    *((unsigned int *)t24) = 1;
    goto LAB252;

LAB251:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB252;

LAB253:    t44 = *((unsigned int *)t31);
    t52 = *((unsigned int *)t30);
    *((unsigned int *)t31) = (t44 | t52);
    t32 = (t6 + 4);
    t34 = (t24 + 4);
    t53 = *((unsigned int *)t6);
    t54 = (~(t53));
    t55 = *((unsigned int *)t32);
    t56 = (~(t55));
    t57 = *((unsigned int *)t24);
    t58 = (~(t57));
    t59 = *((unsigned int *)t34);
    t60 = (~(t59));
    t85 = (t54 & t56);
    t86 = (t58 & t60);
    t61 = (~(t85));
    t62 = (~(t86));
    t63 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t63 & t61);
    t64 = *((unsigned int *)t30);
    *((unsigned int *)t30) = (t64 & t62);
    t65 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t65 & t61);
    t66 = *((unsigned int *)t31);
    *((unsigned int *)t31) = (t66 & t62);
    goto LAB255;

LAB256:    xsi_set_current_line(141, ng0);
    xsi_vlogfile_write(1, 0, 0, ng28, 1, t0);
    goto LAB258;

LAB259:    xsi_set_current_line(145, ng0);
    t2 = (t0 + 600U);
    t3 = *((char **)t2);
    memset(t6, 0, 8);
    t2 = (t3 + 4);
    t8 = *((unsigned int *)t2);
    t9 = (~(t8));
    t10 = *((unsigned int *)t3);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB260;

LAB261:    if (*((unsigned int *)t2) != 0)
        goto LAB262;

LAB263:    t5 = (t6 + 4);
    t15 = *((unsigned int *)t6);
    t16 = *((unsigned int *)t5);
    t17 = (t15 || t16);
    if (t17 > 0)
        goto LAB264;

LAB265:    memcpy(t33, t6, 8);

LAB266:    t38 = (t33 + 4);
    t72 = *((unsigned int *)t38);
    t73 = (~(t72));
    t74 = *((unsigned int *)t33);
    t75 = (t74 & t73);
    t76 = (t75 != 0);
    if (t76 > 0)
        goto LAB278;

LAB279:    xsi_set_current_line(148, ng0);
    xsi_vlogfile_write(1, 0, 0, ng31, 1, t0);

LAB280:    xsi_set_current_line(149, ng0);
    t2 = ((char*)((ng15)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(150, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB281;
    goto LAB1;

LAB260:    *((unsigned int *)t6) = 1;
    goto LAB263;

LAB262:    t4 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t4) = 1;
    goto LAB263;

LAB264:    t7 = (t0 + 784U);
    t13 = *((char **)t7);
    memset(t24, 0, 8);
    t7 = (t13 + 4);
    t18 = *((unsigned int *)t7);
    t19 = (~(t18));
    t20 = *((unsigned int *)t13);
    t21 = (t20 & t19);
    t22 = (t21 & 1U);
    if (t22 != 0)
        goto LAB270;

LAB268:    if (*((unsigned int *)t7) == 0)
        goto LAB267;

LAB269:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;

LAB270:    memset(t31, 0, 8);
    t23 = (t24 + 4);
    t25 = *((unsigned int *)t23);
    t26 = (~(t25));
    t27 = *((unsigned int *)t24);
    t28 = (t27 & t26);
    t40 = (t28 & 1U);
    if (t40 != 0)
        goto LAB271;

LAB272:    if (*((unsigned int *)t23) != 0)
        goto LAB273;

LAB274:    t41 = *((unsigned int *)t6);
    t42 = *((unsigned int *)t31);
    t43 = (t41 & t42);
    *((unsigned int *)t33) = t43;
    t30 = (t6 + 4);
    t32 = (t31 + 4);
    t34 = (t33 + 4);
    t44 = *((unsigned int *)t30);
    t52 = *((unsigned int *)t32);
    t53 = (t44 | t52);
    *((unsigned int *)t34) = t53;
    t54 = *((unsigned int *)t34);
    t55 = (t54 != 0);
    if (t55 == 1)
        goto LAB275;

LAB276:
LAB277:    goto LAB266;

LAB267:    *((unsigned int *)t24) = 1;
    goto LAB270;

LAB271:    *((unsigned int *)t31) = 1;
    goto LAB274;

LAB273:    t29 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t29) = 1;
    goto LAB274;

LAB275:    t56 = *((unsigned int *)t33);
    t57 = *((unsigned int *)t34);
    *((unsigned int *)t33) = (t56 | t57);
    t35 = (t6 + 4);
    t37 = (t31 + 4);
    t58 = *((unsigned int *)t6);
    t59 = (~(t58));
    t60 = *((unsigned int *)t35);
    t61 = (~(t60));
    t62 = *((unsigned int *)t31);
    t63 = (~(t62));
    t64 = *((unsigned int *)t37);
    t65 = (~(t64));
    t85 = (t59 & t61);
    t86 = (t63 & t65);
    t66 = (~(t85));
    t67 = (~(t86));
    t68 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t68 & t66);
    t69 = *((unsigned int *)t34);
    *((unsigned int *)t34) = (t69 & t67);
    t70 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t70 & t66);
    t71 = *((unsigned int *)t33);
    *((unsigned int *)t33) = (t71 & t67);
    goto LAB277;

LAB278:    xsi_set_current_line(146, ng0);
    xsi_vlogfile_write(1, 0, 0, ng30, 1, t0);
    goto LAB280;

LAB281:    xsi_set_current_line(151, ng0);
    xsi_set_current_line(151, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB282:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng32)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB283;

LAB284:    xsi_set_current_line(157, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(158, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 20000LL);
    *((char **)t1) = &&LAB293;
    goto LAB1;

LAB283:    xsi_set_current_line(152, ng0);

LAB285:    xsi_set_current_line(153, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB286;
    goto LAB1;

LAB286:    xsi_set_current_line(154, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng4)));
    memset(t6, 0, 8);
    xsi_vlog_signed_multiply(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 1840);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 5);
    xsi_set_current_line(155, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB290;

LAB288:    if (*((unsigned int *)t5) == 0)
        goto LAB287;

LAB289:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB290:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB292;

LAB291:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(151, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB282;

LAB287:    *((unsigned int *)t6) = 1;
    goto LAB290;

LAB292:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB291;

LAB293:    xsi_set_current_line(159, ng0);
    xsi_set_current_line(159, ng0);
    t2 = ((char*)((ng3)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB294:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng32)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB295;

LAB296:    xsi_set_current_line(164, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1932);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 1);
    xsi_set_current_line(165, ng0);
    t2 = ((char*)((ng10)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(166, ng0);
    xsi_set_current_line(166, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 2116);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 32);

LAB305:    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng11)));
    memset(t6, 0, 8);
    xsi_vlog_signed_less(t6, 32, t4, 32, t5, 32);
    t7 = (t6 + 4);
    t8 = *((unsigned int *)t7);
    t9 = (~(t8));
    t10 = *((unsigned int *)t6);
    t11 = (t10 & t9);
    t12 = (t11 != 0);
    if (t12 > 0)
        goto LAB306;

LAB307:    xsi_set_current_line(168, ng0);
    t2 = ((char*)((ng1)));
    t3 = (t0 + 1748);
    xsi_vlogvar_assign_value(t3, t2, 0, 0, 3);
    xsi_set_current_line(169, ng0);
    t2 = (t0 + 1244U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng1)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t8 = *((unsigned int *)t3);
    t9 = *((unsigned int *)t2);
    t10 = (t8 ^ t9);
    t11 = *((unsigned int *)t4);
    t12 = *((unsigned int *)t5);
    t15 = (t11 ^ t12);
    t16 = (t10 | t15);
    t17 = *((unsigned int *)t4);
    t18 = *((unsigned int *)t5);
    t19 = (t17 | t18);
    t20 = (~(t19));
    t21 = (t16 & t20);
    if (t21 != 0)
        goto LAB312;

LAB309:    if (t19 != 0)
        goto LAB311;

LAB310:    *((unsigned int *)t6) = 1;

LAB312:    memset(t24, 0, 8);
    t13 = (t6 + 4);
    t22 = *((unsigned int *)t13);
    t25 = (~(t22));
    t26 = *((unsigned int *)t6);
    t27 = (t26 & t25);
    t28 = (t27 & 1U);
    if (t28 != 0)
        goto LAB313;

LAB314:    if (*((unsigned int *)t13) != 0)
        goto LAB315;

LAB316:    t23 = (t24 + 4);
    t40 = *((unsigned int *)t24);
    t41 = *((unsigned int *)t23);
    t42 = (t40 || t41);
    if (t42 > 0)
        goto LAB317;

LAB318:    memcpy(t36, t24, 8);

LAB319:    t50 = (t36 + 4);
    t93 = *((unsigned int *)t50);
    t94 = (~(t93));
    t95 = *((unsigned int *)t36);
    t96 = (t95 & t94);
    t97 = (t96 != 0);
    if (t97 > 0)
        goto LAB331;

LAB332:    xsi_set_current_line(172, ng0);
    xsi_vlogfile_write(1, 0, 0, ng35, 1, t0);

LAB333:    xsi_set_current_line(173, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 539810000LL);
    *((char **)t1) = &&LAB334;
    goto LAB1;

LAB295:    xsi_set_current_line(160, ng0);

LAB297:    xsi_set_current_line(161, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB298;
    goto LAB1;

LAB298:    xsi_set_current_line(162, ng0);
    t2 = (t0 + 1932);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = *((unsigned int *)t5);
    t9 = (~(t8));
    t10 = *((unsigned int *)t4);
    t11 = (t10 & t9);
    t12 = (t11 & 1U);
    if (t12 != 0)
        goto LAB302;

LAB300:    if (*((unsigned int *)t5) == 0)
        goto LAB299;

LAB301:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;

LAB302:    t13 = (t6 + 4);
    t14 = (t4 + 4);
    t15 = *((unsigned int *)t4);
    t16 = (~(t15));
    *((unsigned int *)t6) = t16;
    *((unsigned int *)t13) = 0;
    if (*((unsigned int *)t14) != 0)
        goto LAB304;

LAB303:    t21 = *((unsigned int *)t6);
    *((unsigned int *)t6) = (t21 & 1U);
    t22 = *((unsigned int *)t13);
    *((unsigned int *)t13) = (t22 & 1U);
    t23 = (t0 + 1932);
    xsi_vlogvar_assign_value(t23, t6, 0, 0, 1);
    xsi_set_current_line(159, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB294;

LAB299:    *((unsigned int *)t6) = 1;
    goto LAB302;

LAB304:    t17 = *((unsigned int *)t6);
    t18 = *((unsigned int *)t14);
    *((unsigned int *)t6) = (t17 | t18);
    t19 = *((unsigned int *)t13);
    t20 = *((unsigned int *)t14);
    *((unsigned int *)t13) = (t19 | t20);
    goto LAB303;

LAB306:    xsi_set_current_line(167, ng0);
    t13 = (t0 + 2828);
    xsi_process_wait(t13, 10000LL);
    *((char **)t1) = &&LAB308;
    goto LAB1;

LAB308:    xsi_set_current_line(166, ng0);
    t2 = (t0 + 2116);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_signed_add(t6, 32, t4, 32, t5, 32);
    t7 = (t0 + 2116);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 32);
    goto LAB305;

LAB311:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB312;

LAB313:    *((unsigned int *)t24) = 1;
    goto LAB316;

LAB315:    t14 = (t24 + 4);
    *((unsigned int *)t24) = 1;
    *((unsigned int *)t14) = 1;
    goto LAB316;

LAB317:    t29 = (t0 + 1520U);
    t30 = *((char **)t29);
    t29 = ((char*)((ng33)));
    memset(t31, 0, 8);
    t32 = (t30 + 4);
    t34 = (t29 + 4);
    t43 = *((unsigned int *)t30);
    t44 = *((unsigned int *)t29);
    t52 = (t43 ^ t44);
    t53 = *((unsigned int *)t32);
    t54 = *((unsigned int *)t34);
    t55 = (t53 ^ t54);
    t56 = (t52 | t55);
    t57 = *((unsigned int *)t32);
    t58 = *((unsigned int *)t34);
    t59 = (t57 | t58);
    t60 = (~(t59));
    t61 = (t56 & t60);
    if (t61 != 0)
        goto LAB323;

LAB320:    if (t59 != 0)
        goto LAB322;

LAB321:    *((unsigned int *)t31) = 1;

LAB323:    memset(t33, 0, 8);
    t37 = (t31 + 4);
    t62 = *((unsigned int *)t37);
    t63 = (~(t62));
    t64 = *((unsigned int *)t31);
    t65 = (t64 & t63);
    t66 = (t65 & 1U);
    if (t66 != 0)
        goto LAB324;

LAB325:    if (*((unsigned int *)t37) != 0)
        goto LAB326;

LAB327:    t67 = *((unsigned int *)t24);
    t68 = *((unsigned int *)t33);
    t69 = (t67 & t68);
    *((unsigned int *)t36) = t69;
    t39 = (t24 + 4);
    t45 = (t33 + 4);
    t46 = (t36 + 4);
    t70 = *((unsigned int *)t39);
    t71 = *((unsigned int *)t45);
    t72 = (t70 | t71);
    *((unsigned int *)t46) = t72;
    t73 = *((unsigned int *)t46);
    t74 = (t73 != 0);
    if (t74 == 1)
        goto LAB328;

LAB329:
LAB330:    goto LAB319;

LAB322:    t35 = (t31 + 4);
    *((unsigned int *)t31) = 1;
    *((unsigned int *)t35) = 1;
    goto LAB323;

LAB324:    *((unsigned int *)t33) = 1;
    goto LAB327;

LAB326:    t38 = (t33 + 4);
    *((unsigned int *)t33) = 1;
    *((unsigned int *)t38) = 1;
    goto LAB327;

LAB328:    t75 = *((unsigned int *)t36);
    t76 = *((unsigned int *)t46);
    *((unsigned int *)t36) = (t75 | t76);
    t47 = (t24 + 4);
    t48 = (t33 + 4);
    t77 = *((unsigned int *)t24);
    t78 = (~(t77));
    t79 = *((unsigned int *)t47);
    t80 = (~(t79));
    t81 = *((unsigned int *)t33);
    t82 = (~(t81));
    t83 = *((unsigned int *)t48);
    t84 = (~(t83));
    t85 = (t78 & t80);
    t86 = (t82 & t84);
    t87 = (~(t85));
    t88 = (~(t86));
    t89 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t89 & t87);
    t90 = *((unsigned int *)t46);
    *((unsigned int *)t46) = (t90 & t88);
    t91 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t91 & t87);
    t92 = *((unsigned int *)t36);
    *((unsigned int *)t36) = (t92 & t88);
    goto LAB330;

LAB331:    xsi_set_current_line(170, ng0);
    xsi_vlogfile_write(1, 0, 0, ng34, 1, t0);
    goto LAB333;

LAB334:    xsi_set_current_line(174, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 968U);
    t4 = *((char **)t2);
    t2 = (t0 + 1060U);
    t5 = *((char **)t2);
    t2 = (t0 + 1152U);
    t7 = *((char **)t2);
    t2 = (t0 + 1428U);
    t13 = *((char **)t2);
    t2 = (t0 + 600U);
    t14 = *((char **)t2);
    t2 = (t0 + 692U);
    t23 = *((char **)t2);
    t2 = (t0 + 1244U);
    t29 = *((char **)t2);
    t2 = (t0 + 1336U);
    t30 = *((char **)t2);
    t2 = (t0 + 1520U);
    t32 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng36, 11, t0, (char)118, t3, 4, (char)118, t4, 6, (char)118, t5, 6, (char)118, t7, 1, (char)118, t13, 7, (char)118, t14, 1, (char)118, t23, 1, (char)118, t29, 5, (char)118, t30, 5, (char)118, t32, 5);
    xsi_set_current_line(175, ng0);
    t2 = (t0 + 2828);
    xsi_process_wait(t2, 10000LL);
    *((char **)t1) = &&LAB335;
    goto LAB1;

LAB335:    xsi_set_current_line(176, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = (t0 + 968U);
    t4 = *((char **)t2);
    t2 = (t0 + 1060U);
    t5 = *((char **)t2);
    t2 = (t0 + 1152U);
    t7 = *((char **)t2);
    t2 = (t0 + 1428U);
    t13 = *((char **)t2);
    t2 = (t0 + 600U);
    t14 = *((char **)t2);
    t2 = (t0 + 692U);
    t23 = *((char **)t2);
    t2 = (t0 + 1244U);
    t29 = *((char **)t2);
    t2 = (t0 + 1336U);
    t30 = *((char **)t2);
    t2 = (t0 + 1520U);
    t32 = *((char **)t2);
    xsi_vlogfile_write(1, 0, 0, ng36, 11, t0, (char)118, t3, 4, (char)118, t4, 6, (char)118, t5, 6, (char)118, t7, 1, (char)118, t13, 7, (char)118, t14, 1, (char)118, t23, 1, (char)118, t29, 5, (char)118, t30, 5, (char)118, t32, 5);
    xsi_set_current_line(177, ng0);
    xsi_vlog_finish(1);
    goto LAB1;

}


extern void work_m_00000000000282797418_1949178628_init()
{
	static char *pe[] = {(void *)Initial_47_0,(void *)Always_48_1,(void *)Initial_51_2};
	xsi_register_didat("work_m_00000000000282797418_1949178628", "isim/testbench_isim_beh.exe.sim/work/m_00000000000282797418_1949178628.didat");
	xsi_register_executes(pe);
}
