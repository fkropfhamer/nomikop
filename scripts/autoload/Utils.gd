extends Node

func get_scene_manager():
	return get_node(NodePath("/root/SceneManager"))
	
func transition_to_scene(scene_path):
	get_scene_manager().transition_to_scene(NodePath(scene_path))
