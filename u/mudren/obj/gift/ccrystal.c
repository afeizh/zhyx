// ccrystal.c ˮ����Ƭ

#include <ansi.h>
#include <armor.h>

inherit HEAD;

void create()
{
	set_name(HIM "ˮ����Ƭ" NOR, ({ "chipped crystal" }) );
	set_weight(25);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", HIM "һƬ��ɫ��ˮ����Ƭ��\n" NOR);
                set("value", 20000);
		set("unit", "Ƭ");
                set("can_be_enchased", 1);
                set("magic/type", "magic");
                set("magic/power", 50);
                set("armor_prop/personality", 3);
                set("wear_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "����ͷ�ϡ�\n" NOR);
                set("remove_msg", HIC "$N" HIC "����ذ�$n"
                    HIC "��ͷ��ժ��������\n" NOR);
	}
        setup();
}

int query_autoload() { return 1; }