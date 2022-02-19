extends Area2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

export(String, FILE) var next_scene_path


# Called when the node enters the scene tree for the first time.
func _ready():
	var player = find_parent("CurrentScene").get_children().back().find_node("Player")
	player.connect("player_entered_door_signal", self, "entered_door")
	pass # Replace with function body.

func entered_door():
	get_node(NodePath("/root/SceneManager")).transition_to_scene(next_scene_path)

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
