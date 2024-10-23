#include "GameTestNode.h"
#include "core/string/print_string.h"
void GameTestNode::_ready() {
    print_line("GameTestNode::_ready()!");
    _err_print_error(__FUNCTION__,__FILE__,__LINE__,"GameTestNode::Ready!");
}

void GameTestNode::_exit_tree() {
    print_line("GameTestNode::_exit_tree()!");
}
