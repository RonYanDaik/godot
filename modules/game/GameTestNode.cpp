#include "GameTestNode.h"
#include "core/string/print_string.h"

void GameTestNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("test"), &GameTestNode::test);
}

void GameTestNode::_ready() {
	print_line("GameTestNode::_ready()!");
    _err_print_error(__FUNCTION__,__FILE__,__LINE__,"GameTestNode::Ready!");
}

void GameTestNode::_exit_tree() {
    print_line("GameTestNode::_exit_tree()!");
}

void GameTestNode::_notification(int p_notification){
    switch (p_notification) {
		case NOTIFICATION_PROCESS: {
			//GDVIRTUAL_CALL(_process, get_process_delta_time());
		} break;

		case NOTIFICATION_PHYSICS_PROCESS: {
			//GDVIRTUAL_CALL(_physics_process, get_physics_process_delta_time());
		} break;

		case NOTIFICATION_ENTER_TREE: {
			/*ERR_FAIL_NULL(get_viewport());
			ERR_FAIL_NULL(get_tree());

			// Update process mode.
			if (data.process_mode == PROCESS_MODE_INHERIT) {
				if (data.parent) {
					data.process_owner = data.parent->data.process_owner;
				} else {
					ERR_PRINT("The root node can't be set to Inherit process mode, reverting to Pausable instead.");
					data.process_mode = PROCESS_MODE_PAUSABLE;
					data.process_owner = this;
				}
			} else {
				data.process_owner = this;
			}

			{ // Update threaded process mode.
				if (data.process_thread_group == PROCESS_THREAD_GROUP_INHERIT) {
					if (data.parent) {
						data.process_thread_group_owner = data.parent->data.process_thread_group_owner;
					}

					if (data.process_thread_group_owner) {
						data.process_group = data.process_thread_group_owner->data.process_group;
					} else {
						data.process_group = &data.tree->default_process_group;
					}
				} else {
					data.process_thread_group_owner = this;
					_add_process_group();
				}

				if (_is_any_processing()) {
					_add_to_process_thread_group();
				}
			}

			if (data.physics_interpolation_mode == PHYSICS_INTERPOLATION_MODE_INHERIT) {
				bool interpolate = true; // Root node default is for interpolation to be on.
				if (data.parent) {
					interpolate = data.parent->is_physics_interpolated();
				}
				_propagate_physics_interpolated(interpolate);
			}

			// Update auto translate mode.
			if (data.auto_translate_mode == AUTO_TRANSLATE_MODE_INHERIT && !data.parent) {
				ERR_PRINT("The root node can't be set to Inherit auto translate mode, reverting to Always instead.");
				data.auto_translate_mode = AUTO_TRANSLATE_MODE_ALWAYS;
			}
			data.is_auto_translate_dirty = true;
			data.is_translation_domain_dirty = true;

#ifdef TOOLS_ENABLED
			// Don't translate UI elements when they're being edited.
			if (is_part_of_edited_scene()) {
				set_message_translation(false);
			}
#endif

			if (data.input) {
				add_to_group("_vp_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.shortcut_input) {
				add_to_group("_vp_shortcut_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.unhandled_input) {
				add_to_group("_vp_unhandled_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.unhandled_key_input) {
				add_to_group("_vp_unhandled_key_input" + itos(get_viewport()->get_instance_id()));
			}

			get_tree()->nodes_in_tree_count++;
			orphan_node_count--;

			// Allow physics interpolated nodes to automatically reset when added to the tree
			// (this is to save the user from doing this manually each time).
			if (get_tree()->is_physics_interpolation_enabled()) {
				_set_physics_interpolation_reset_requested(true);
			}*/
		} break;

		case NOTIFICATION_POST_ENTER_TREE: {
			/*if (data.auto_translate_mode != AUTO_TRANSLATE_MODE_DISABLED) {
				notification(NOTIFICATION_TRANSLATION_CHANGED);
			}*/
		} break;

		case NOTIFICATION_EXIT_TREE: {
			/*ERR_FAIL_NULL(get_viewport());
			ERR_FAIL_NULL(get_tree());

			get_tree()->nodes_in_tree_count--;
			orphan_node_count++;

			if (data.input) {
				remove_from_group("_vp_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.shortcut_input) {
				remove_from_group("_vp_shortcut_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.unhandled_input) {
				remove_from_group("_vp_unhandled_input" + itos(get_viewport()->get_instance_id()));
			}
			if (data.unhandled_key_input) {
				remove_from_group("_vp_unhandled_key_input" + itos(get_viewport()->get_instance_id()));
			}

			// Remove from processing first.
			if (_is_any_processing()) {
				_remove_from_process_thread_group();
			}
			// Remove the process group.
			if (data.process_thread_group_owner == this) {
				_remove_process_group();
			}
			data.process_thread_group_owner = nullptr;
			data.process_owner = nullptr;

			if (data.path_cache) {
				memdelete(data.path_cache);
				data.path_cache = nullptr;
			}*/
		} break;

		case NOTIFICATION_SUSPENDED:
		case NOTIFICATION_PAUSED: {
			/*if (is_physics_interpolated_and_enabled() && is_inside_tree()) {
				reset_physics_interpolation();
			}*/
		} break;

		case NOTIFICATION_PATH_RENAMED: {
			/*if (data.path_cache) {
				memdelete(data.path_cache);
				data.path_cache = nullptr;
			}*/
		} break;

		case NOTIFICATION_READY: {
			/*if (GDVIRTUAL_IS_OVERRIDDEN(_input)) {
				set_process_input(true);
			}

			if (GDVIRTUAL_IS_OVERRIDDEN(_shortcut_input)) {
				set_process_shortcut_input(true);
			}

			if (GDVIRTUAL_IS_OVERRIDDEN(_unhandled_input)) {
				set_process_unhandled_input(true);
			}

			if (GDVIRTUAL_IS_OVERRIDDEN(_unhandled_key_input)) {
				set_process_unhandled_key_input(true);
			}

			if (GDVIRTUAL_IS_OVERRIDDEN(_process)) {
				set_process(true);
			}
			if (GDVIRTUAL_IS_OVERRIDDEN(_physics_process)) {
				set_physics_process(true);
			}*/

			_ready();
		} break;

		case NOTIFICATION_POSTINITIALIZE: {
			//data.in_constructor = false;
		} break;

		case NOTIFICATION_PREDELETE: {
			/*if (data.inside_tree && !Thread::is_main_thread()) {
				cancel_free();
				ERR_PRINT("Attempted to free a node that is currently added to the SceneTree from a thread. This is not permitted, use queue_free() instead. Node has not been freed.");
				return;
			}

			if (data.owner) {
				_clean_up_owner();
			}

			while (!data.owned.is_empty()) {
				Node *n = data.owned.back()->get();
				n->_clean_up_owner(); // This will change data.owned. So it's impossible to loop over the list in the usual manner.
			}

			if (data.parent) {
				data.parent->remove_child(this);
			}

			// kill children as cleanly as possible
			while (data.children.size()) {
				Node *child = data.children.last()->value; // begin from the end because its faster and more consistent with creation
				memdelete(child);
			}*/
		} break;

		case NOTIFICATION_TRANSLATION_CHANGED: {
			/*if (data.inside_tree) {
				data.is_auto_translate_dirty = true;
			}*/
		} break;
	}
}
