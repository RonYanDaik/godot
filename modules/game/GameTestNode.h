#ifndef A9FE702C_DF29_4C0A_A846_CF80656E1223
#define A9FE702C_DF29_4C0A_A846_CF80656E1223

#include "scene/main/node.h"

class GameTestNode : public Node {
    GDCLASS(GameTestNode , Node)
    protected:
    static void _bind_methods();
    public:

    void _ready();

    void _exit_tree();
    void test(){};

    void _process(double delta){}

    void _notification(int p_notification);
};

#endif /* A9FE702C_DF29_4C0A_A846_CF80656E1223 */
