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
static const char *ng0 = "D:/CENG/2-2/CENG232/lab3/lab3_part2/lab3_2.v";
static unsigned int ng1[] = {1U, 0U};
static unsigned int ng2[] = {0U, 0U};
static int ng3[] = {1, 0};
static int ng4[] = {0, 0};



static void Initial_15_0(char *t0)
{
    char *t1;
    char *t2;

LAB0:    xsi_set_current_line(16, ng0);

LAB2:    xsi_set_current_line(17, ng0);
    t1 = (t0 + 600U);
    t2 = *((char **)t1);
    t1 = (t0 + 1196);
    xsi_vlogvar_assign_value(t1, t2, 0, 0, 8);
    xsi_set_current_line(18, ng0);
    t1 = (t0 + 600U);
    t2 = *((char **)t1);
    t1 = (t0 + 1288);
    xsi_vlogvar_assign_value(t1, t2, 0, 0, 8);
    xsi_set_current_line(19, ng0);
    t1 = ((char*)((ng1)));
    t2 = (t0 + 1380);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);
    xsi_set_current_line(20, ng0);
    t1 = ((char*)((ng2)));
    t2 = (t0 + 1472);
    xsi_vlogvar_assign_value(t2, t1, 0, 0, 1);

LAB1:    return;
}

static void Always_25_1(char *t0)
{
    char t6[8];
    char t30[8];
    char t55[8];
    char t65[8];
    char t69[8];
    char t70[8];
    char t76[8];
    char t84[8];
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t7;
    char *t8;
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
    unsigned int t19;
    unsigned int t20;
    char *t21;
    char *t22;
    unsigned int t23;
    unsigned int t24;
    unsigned int t25;
    unsigned int t26;
    unsigned int t27;
    char *t28;
    char *t29;
    char *t31;
    char *t32;
    unsigned int t33;
    unsigned int t34;
    unsigned int t35;
    unsigned int t36;
    unsigned int t37;
    unsigned int t38;
    unsigned int t39;
    unsigned int t40;
    unsigned int t41;
    unsigned int t42;
    unsigned int t43;
    unsigned int t44;
    char *t45;
    char *t46;
    unsigned int t47;
    unsigned int t48;
    unsigned int t49;
    unsigned int t50;
    unsigned int t51;
    char *t52;
    char *t53;
    char *t54;
    char *t56;
    char *t57;
    char *t58;
    char *t59;
    char *t60;
    char *t61;
    char *t62;
    char *t63;
    char *t64;
    char *t66;
    char *t67;
    char *t68;
    char *t71;
    unsigned int t72;
    unsigned int t73;
    unsigned int t74;
    char *t75;
    char *t77;
    unsigned int t78;
    unsigned int t79;
    unsigned int t80;
    unsigned int t81;
    unsigned int t82;
    char *t83;
    unsigned int t85;
    unsigned int t86;
    unsigned int t87;
    char *t88;
    char *t89;
    char *t90;
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
    unsigned int t103;
    unsigned int t104;
    unsigned int t105;
    unsigned int t106;
    unsigned int t107;
    int t108;
    int t109;
    unsigned int t110;
    unsigned int t111;
    unsigned int t112;
    unsigned int t113;
    unsigned int t114;
    unsigned int t115;
    char *t116;
    unsigned int t117;
    unsigned int t118;
    unsigned int t119;
    unsigned int t120;
    unsigned int t121;
    char *t122;
    char *t123;

LAB0:    t1 = (t0 + 2140U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    xsi_set_current_line(25, ng0);
    t2 = (t0 + 2336);
    *((int *)t2) = 1;
    t3 = (t0 + 2168);
    *((char **)t3) = t2;
    *((char **)t1) = &&LAB4;

LAB1:    return;
LAB4:    xsi_set_current_line(26, ng0);

LAB5:    xsi_set_current_line(27, ng0);
    t4 = (t0 + 784U);
    t5 = *((char **)t4);
    t4 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t7 = (t5 + 4);
    t8 = (t4 + 4);
    t9 = *((unsigned int *)t5);
    t10 = *((unsigned int *)t4);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB9;

LAB6:    if (t18 != 0)
        goto LAB8;

LAB7:    *((unsigned int *)t6) = 1;

LAB9:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB10;

LAB11:
LAB12:    goto LAB2;

LAB8:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB9;

LAB10:    xsi_set_current_line(28, ng0);

LAB13:    xsi_set_current_line(30, ng0);
    t28 = (t0 + 876U);
    t29 = *((char **)t28);
    t28 = ((char*)((ng4)));
    memset(t30, 0, 8);
    t31 = (t29 + 4);
    t32 = (t28 + 4);
    t33 = *((unsigned int *)t29);
    t34 = *((unsigned int *)t28);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t31);
    t37 = *((unsigned int *)t32);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t31);
    t41 = *((unsigned int *)t32);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB17;

LAB14:    if (t42 != 0)
        goto LAB16;

LAB15:    *((unsigned int *)t30) = 1;

LAB17:    t46 = (t30 + 4);
    t47 = *((unsigned int *)t46);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB18;

LAB19:    xsi_set_current_line(46, ng0);
    t2 = (t0 + 876U);
    t3 = *((char **)t2);
    t2 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t4 = (t3 + 4);
    t5 = (t2 + 4);
    t9 = *((unsigned int *)t3);
    t10 = *((unsigned int *)t2);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t4);
    t13 = *((unsigned int *)t5);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t4);
    t17 = *((unsigned int *)t5);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB92;

LAB89:    if (t18 != 0)
        goto LAB91;

LAB90:    *((unsigned int *)t6) = 1;

LAB92:    t8 = (t6 + 4);
    t23 = *((unsigned int *)t8);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB93;

LAB94:
LAB95:
LAB20:    goto LAB12;

LAB16:    t45 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t45) = 1;
    goto LAB17;

LAB18:    xsi_set_current_line(31, ng0);

LAB21:    xsi_set_current_line(32, ng0);
    t52 = ((char*)((ng4)));
    t53 = (t0 + 1380);
    xsi_vlogvar_assign_value(t53, t52, 0, 0, 1);
    xsi_set_current_line(33, ng0);
    t2 = (t0 + 1472);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB23;

LAB22:    if (t18 != 0)
        goto LAB24;

LAB25:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB26;

LAB27:
LAB28:    goto LAB20;

LAB23:    *((unsigned int *)t6) = 1;
    goto LAB25;

LAB24:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB25;

LAB26:    xsi_set_current_line(34, ng0);

LAB29:    xsi_set_current_line(35, ng0);
    t28 = (t0 + 1288);
    t29 = (t28 + 36U);
    t31 = *((char **)t29);
    t32 = (t0 + 1196);
    t45 = (t32 + 36U);
    t46 = *((char **)t45);
    memset(t30, 0, 8);
    t52 = (t31 + 4);
    if (*((unsigned int *)t52) != 0)
        goto LAB31;

LAB30:    t53 = (t46 + 4);
    if (*((unsigned int *)t53) != 0)
        goto LAB31;

LAB34:    if (*((unsigned int *)t31) > *((unsigned int *)t46))
        goto LAB32;

LAB33:    memset(t55, 0, 8);
    t56 = (t30 + 4);
    t33 = *((unsigned int *)t56);
    t34 = (~(t33));
    t35 = *((unsigned int *)t30);
    t36 = (t35 & t34);
    t37 = (t36 & 1U);
    if (t37 != 0)
        goto LAB35;

LAB36:    if (*((unsigned int *)t56) != 0)
        goto LAB37;

LAB38:    t58 = (t55 + 4);
    t38 = *((unsigned int *)t55);
    t39 = *((unsigned int *)t58);
    t40 = (t38 || t39);
    if (t40 > 0)
        goto LAB39;

LAB40:    memcpy(t84, t55, 8);

LAB41:    t116 = (t84 + 4);
    t117 = *((unsigned int *)t116);
    t118 = (~(t117));
    t119 = *((unsigned int *)t84);
    t120 = (t119 & t118);
    t121 = (t120 != 0);
    if (t121 > 0)
        goto LAB53;

LAB54:    xsi_set_current_line(37, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t7 = (t5 + 36U);
    t8 = *((char **)t7);
    memset(t6, 0, 8);
    t21 = (t4 + 4);
    if (*((unsigned int *)t21) != 0)
        goto LAB57;

LAB56:    t22 = (t8 + 4);
    if (*((unsigned int *)t22) != 0)
        goto LAB57;

LAB60:    if (*((unsigned int *)t4) > *((unsigned int *)t8))
        goto LAB58;

LAB59:    memset(t30, 0, 8);
    t29 = (t6 + 4);
    t9 = *((unsigned int *)t29);
    t10 = (~(t9));
    t11 = *((unsigned int *)t6);
    t12 = (t11 & t10);
    t13 = (t12 & 1U);
    if (t13 != 0)
        goto LAB61;

LAB62:    if (*((unsigned int *)t29) != 0)
        goto LAB63;

LAB64:    t32 = (t30 + 4);
    t14 = *((unsigned int *)t30);
    t15 = *((unsigned int *)t32);
    t16 = (t14 || t15);
    if (t16 > 0)
        goto LAB65;

LAB66:    memcpy(t70, t30, 8);

LAB67:    t71 = (t70 + 4);
    t95 = *((unsigned int *)t71);
    t96 = (~(t95));
    t97 = *((unsigned int *)t70);
    t100 = (t97 & t96);
    t101 = (t100 != 0);
    if (t101 > 0)
        goto LAB79;

LAB80:
LAB81:
LAB55:    xsi_set_current_line(39, ng0);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 692U);
    t7 = *((char **)t5);
    memset(t6, 0, 8);
    t5 = (t4 + 4);
    t8 = (t7 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t7);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t5);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t5);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB85;

LAB82:    if (t18 != 0)
        goto LAB84;

LAB83:    *((unsigned int *)t6) = 1;

LAB85:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB86;

LAB87:    xsi_set_current_line(42, ng0);
    t2 = (t0 + 1288);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 8, t5, 32);
    t7 = (t0 + 1288);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 8);

LAB88:    goto LAB28;

LAB31:    t54 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t54) = 1;
    goto LAB33;

LAB32:    *((unsigned int *)t30) = 1;
    goto LAB33;

LAB35:    *((unsigned int *)t55) = 1;
    goto LAB38;

LAB37:    t57 = (t55 + 4);
    *((unsigned int *)t55) = 1;
    *((unsigned int *)t57) = 1;
    goto LAB38;

LAB39:    t59 = (t0 + 1288);
    t60 = (t59 + 36U);
    t61 = *((char **)t60);
    t62 = (t0 + 1196);
    t63 = (t62 + 36U);
    t64 = *((char **)t63);
    memset(t65, 0, 8);
    xsi_vlog_unsigned_minus(t65, 8, t61, 8, t64, 8);
    t66 = (t0 + 692U);
    t67 = *((char **)t66);
    t66 = (t0 + 600U);
    t68 = *((char **)t66);
    memset(t69, 0, 8);
    xsi_vlog_unsigned_minus(t69, 8, t67, 8, t68, 8);
    memset(t70, 0, 8);
    t66 = (t65 + 4);
    t71 = (t69 + 4);
    t41 = *((unsigned int *)t65);
    t42 = *((unsigned int *)t69);
    t43 = (t41 ^ t42);
    t44 = *((unsigned int *)t66);
    t47 = *((unsigned int *)t71);
    t48 = (t44 ^ t47);
    t49 = (t43 | t48);
    t50 = *((unsigned int *)t66);
    t51 = *((unsigned int *)t71);
    t72 = (t50 | t51);
    t73 = (~(t72));
    t74 = (t49 & t73);
    if (t74 != 0)
        goto LAB45;

LAB42:    if (t72 != 0)
        goto LAB44;

LAB43:    *((unsigned int *)t70) = 1;

LAB45:    memset(t76, 0, 8);
    t77 = (t70 + 4);
    t78 = *((unsigned int *)t77);
    t79 = (~(t78));
    t80 = *((unsigned int *)t70);
    t81 = (t80 & t79);
    t82 = (t81 & 1U);
    if (t82 != 0)
        goto LAB46;

LAB47:    if (*((unsigned int *)t77) != 0)
        goto LAB48;

LAB49:    t85 = *((unsigned int *)t55);
    t86 = *((unsigned int *)t76);
    t87 = (t85 & t86);
    *((unsigned int *)t84) = t87;
    t88 = (t55 + 4);
    t89 = (t76 + 4);
    t90 = (t84 + 4);
    t91 = *((unsigned int *)t88);
    t92 = *((unsigned int *)t89);
    t93 = (t91 | t92);
    *((unsigned int *)t90) = t93;
    t94 = *((unsigned int *)t90);
    t95 = (t94 != 0);
    if (t95 == 1)
        goto LAB50;

LAB51:
LAB52:    goto LAB41;

LAB44:    t75 = (t70 + 4);
    *((unsigned int *)t70) = 1;
    *((unsigned int *)t75) = 1;
    goto LAB45;

LAB46:    *((unsigned int *)t76) = 1;
    goto LAB49;

LAB48:    t83 = (t76 + 4);
    *((unsigned int *)t76) = 1;
    *((unsigned int *)t83) = 1;
    goto LAB49;

LAB50:    t96 = *((unsigned int *)t84);
    t97 = *((unsigned int *)t90);
    *((unsigned int *)t84) = (t96 | t97);
    t98 = (t55 + 4);
    t99 = (t76 + 4);
    t100 = *((unsigned int *)t55);
    t101 = (~(t100));
    t102 = *((unsigned int *)t98);
    t103 = (~(t102));
    t104 = *((unsigned int *)t76);
    t105 = (~(t104));
    t106 = *((unsigned int *)t99);
    t107 = (~(t106));
    t108 = (t101 & t103);
    t109 = (t105 & t107);
    t110 = (~(t108));
    t111 = (~(t109));
    t112 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t112 & t110);
    t113 = *((unsigned int *)t90);
    *((unsigned int *)t90) = (t113 & t111);
    t114 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t114 & t110);
    t115 = *((unsigned int *)t84);
    *((unsigned int *)t84) = (t115 & t111);
    goto LAB52;

LAB53:    xsi_set_current_line(36, ng0);
    t122 = ((char*)((ng3)));
    t123 = (t0 + 1472);
    xsi_vlogvar_assign_value(t123, t122, 0, 0, 1);
    goto LAB55;

LAB57:    t28 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB59;

LAB58:    *((unsigned int *)t6) = 1;
    goto LAB59;

LAB61:    *((unsigned int *)t30) = 1;
    goto LAB64;

LAB63:    t31 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t31) = 1;
    goto LAB64;

LAB65:    t45 = (t0 + 1196);
    t46 = (t45 + 36U);
    t52 = *((char **)t46);
    t53 = (t0 + 1288);
    t54 = (t53 + 36U);
    t56 = *((char **)t54);
    memset(t55, 0, 8);
    xsi_vlog_unsigned_minus(t55, 32, t52, 8, t56, 8);
    t57 = ((char*)((ng3)));
    memset(t65, 0, 8);
    t58 = (t55 + 4);
    t59 = (t57 + 4);
    t17 = *((unsigned int *)t55);
    t18 = *((unsigned int *)t57);
    t19 = (t17 ^ t18);
    t20 = *((unsigned int *)t58);
    t23 = *((unsigned int *)t59);
    t24 = (t20 ^ t23);
    t25 = (t19 | t24);
    t26 = *((unsigned int *)t58);
    t27 = *((unsigned int *)t59);
    t33 = (t26 | t27);
    t34 = (~(t33));
    t35 = (t25 & t34);
    if (t35 != 0)
        goto LAB71;

LAB68:    if (t33 != 0)
        goto LAB70;

LAB69:    *((unsigned int *)t65) = 1;

LAB71:    memset(t69, 0, 8);
    t61 = (t65 + 4);
    t36 = *((unsigned int *)t61);
    t37 = (~(t36));
    t38 = *((unsigned int *)t65);
    t39 = (t38 & t37);
    t40 = (t39 & 1U);
    if (t40 != 0)
        goto LAB72;

LAB73:    if (*((unsigned int *)t61) != 0)
        goto LAB74;

LAB75:    t41 = *((unsigned int *)t30);
    t42 = *((unsigned int *)t69);
    t43 = (t41 & t42);
    *((unsigned int *)t70) = t43;
    t63 = (t30 + 4);
    t64 = (t69 + 4);
    t66 = (t70 + 4);
    t44 = *((unsigned int *)t63);
    t47 = *((unsigned int *)t64);
    t48 = (t44 | t47);
    *((unsigned int *)t66) = t48;
    t49 = *((unsigned int *)t66);
    t50 = (t49 != 0);
    if (t50 == 1)
        goto LAB76;

LAB77:
LAB78:    goto LAB67;

LAB70:    t60 = (t65 + 4);
    *((unsigned int *)t65) = 1;
    *((unsigned int *)t60) = 1;
    goto LAB71;

LAB72:    *((unsigned int *)t69) = 1;
    goto LAB75;

LAB74:    t62 = (t69 + 4);
    *((unsigned int *)t69) = 1;
    *((unsigned int *)t62) = 1;
    goto LAB75;

LAB76:    t51 = *((unsigned int *)t70);
    t72 = *((unsigned int *)t66);
    *((unsigned int *)t70) = (t51 | t72);
    t67 = (t30 + 4);
    t68 = (t69 + 4);
    t73 = *((unsigned int *)t30);
    t74 = (~(t73));
    t78 = *((unsigned int *)t67);
    t79 = (~(t78));
    t80 = *((unsigned int *)t69);
    t81 = (~(t80));
    t82 = *((unsigned int *)t68);
    t85 = (~(t82));
    t108 = (t74 & t79);
    t109 = (t81 & t85);
    t86 = (~(t108));
    t87 = (~(t109));
    t91 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t91 & t86);
    t92 = *((unsigned int *)t66);
    *((unsigned int *)t66) = (t92 & t87);
    t93 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t93 & t86);
    t94 = *((unsigned int *)t70);
    *((unsigned int *)t70) = (t94 & t87);
    goto LAB78;

LAB79:    xsi_set_current_line(38, ng0);
    t75 = ((char*)((ng3)));
    t77 = (t0 + 1472);
    xsi_vlogvar_assign_value(t77, t75, 0, 0, 1);
    goto LAB81;

LAB84:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB85;

LAB86:    xsi_set_current_line(40, ng0);
    t28 = (t0 + 600U);
    t29 = *((char **)t28);
    t28 = (t0 + 1288);
    xsi_vlogvar_assign_value(t28, t29, 0, 0, 8);
    goto LAB88;

LAB91:    t7 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t7) = 1;
    goto LAB92;

LAB93:    xsi_set_current_line(47, ng0);

LAB96:    xsi_set_current_line(48, ng0);
    t21 = ((char*)((ng4)));
    t22 = (t0 + 1472);
    xsi_vlogvar_assign_value(t22, t21, 0, 0, 1);
    xsi_set_current_line(49, ng0);
    t2 = (t0 + 1380);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    t7 = (t4 + 4);
    t8 = (t5 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t5);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t7);
    t13 = *((unsigned int *)t8);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t7);
    t17 = *((unsigned int *)t8);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB98;

LAB97:    if (t18 != 0)
        goto LAB99;

LAB100:    t22 = (t6 + 4);
    t23 = *((unsigned int *)t22);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB101;

LAB102:
LAB103:    goto LAB95;

LAB98:    *((unsigned int *)t6) = 1;
    goto LAB100;

LAB99:    t21 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t21) = 1;
    goto LAB100;

LAB101:    xsi_set_current_line(50, ng0);

LAB104:    xsi_set_current_line(51, ng0);
    t28 = (t0 + 1196);
    t29 = (t28 + 36U);
    t31 = *((char **)t29);
    t32 = (t0 + 692U);
    t45 = *((char **)t32);
    memset(t30, 0, 8);
    t32 = (t31 + 4);
    t46 = (t45 + 4);
    t33 = *((unsigned int *)t31);
    t34 = *((unsigned int *)t45);
    t35 = (t33 ^ t34);
    t36 = *((unsigned int *)t32);
    t37 = *((unsigned int *)t46);
    t38 = (t36 ^ t37);
    t39 = (t35 | t38);
    t40 = *((unsigned int *)t32);
    t41 = *((unsigned int *)t46);
    t42 = (t40 | t41);
    t43 = (~(t42));
    t44 = (t39 & t43);
    if (t44 != 0)
        goto LAB108;

LAB105:    if (t42 != 0)
        goto LAB107;

LAB106:    *((unsigned int *)t30) = 1;

LAB108:    t53 = (t30 + 4);
    t47 = *((unsigned int *)t53);
    t48 = (~(t47));
    t49 = *((unsigned int *)t30);
    t50 = (t49 & t48);
    t51 = (t50 != 0);
    if (t51 > 0)
        goto LAB109;

LAB110:    xsi_set_current_line(54, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = ((char*)((ng3)));
    memset(t6, 0, 8);
    xsi_vlog_unsigned_add(t6, 32, t4, 8, t5, 32);
    t7 = (t0 + 1196);
    xsi_vlogvar_assign_value(t7, t6, 0, 0, 8);

LAB111:    xsi_set_current_line(55, ng0);
    t2 = (t0 + 1196);
    t3 = (t2 + 36U);
    t4 = *((char **)t3);
    t5 = (t0 + 1288);
    t7 = (t5 + 36U);
    t8 = *((char **)t7);
    memset(t6, 0, 8);
    t21 = (t4 + 4);
    t22 = (t8 + 4);
    t9 = *((unsigned int *)t4);
    t10 = *((unsigned int *)t8);
    t11 = (t9 ^ t10);
    t12 = *((unsigned int *)t21);
    t13 = *((unsigned int *)t22);
    t14 = (t12 ^ t13);
    t15 = (t11 | t14);
    t16 = *((unsigned int *)t21);
    t17 = *((unsigned int *)t22);
    t18 = (t16 | t17);
    t19 = (~(t18));
    t20 = (t15 & t19);
    if (t20 != 0)
        goto LAB115;

LAB112:    if (t18 != 0)
        goto LAB114;

LAB113:    *((unsigned int *)t6) = 1;

LAB115:    t29 = (t6 + 4);
    t23 = *((unsigned int *)t29);
    t24 = (~(t23));
    t25 = *((unsigned int *)t6);
    t26 = (t25 & t24);
    t27 = (t26 != 0);
    if (t27 > 0)
        goto LAB116;

LAB117:
LAB118:    goto LAB103;

LAB107:    t52 = (t30 + 4);
    *((unsigned int *)t30) = 1;
    *((unsigned int *)t52) = 1;
    goto LAB108;

LAB109:    xsi_set_current_line(52, ng0);
    t54 = (t0 + 600U);
    t56 = *((char **)t54);
    t54 = (t0 + 1196);
    xsi_vlogvar_assign_value(t54, t56, 0, 0, 8);
    goto LAB111;

LAB114:    t28 = (t6 + 4);
    *((unsigned int *)t6) = 1;
    *((unsigned int *)t28) = 1;
    goto LAB115;

LAB116:    xsi_set_current_line(56, ng0);
    t31 = ((char*)((ng3)));
    t32 = (t0 + 1380);
    xsi_vlogvar_assign_value(t32, t31, 0, 0, 1);
    goto LAB118;

}


extern void work_m_00000000001978369355_2879598776_init()
{
	static char *pe[] = {(void *)Initial_15_0,(void *)Always_25_1};
	xsi_register_didat("work_m_00000000001978369355_2879598776", "isim/testbench_numerator_isim_beh.exe.sim/work/m_00000000001978369355_2879598776.didat");
	xsi_register_executes(pe);
}
