extends Node2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"

var enemy_health = 100

onready var enemy_health_bar = $EnemyHealthBar

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.

func _unhandled_input(event):
	if event.is_action_pressed("ui_cancel"):
		exit()
		
# Called every frame. 'delta' is the elapsed time since the previous frame
#	pass

func attack():
	enemy_health = enemy_health - 5
	enemy_health_bar.value = enemy_health
	
	if enemy_health <= 0:
		exit()
	


func exit():
	get_node(NodePath("/root/SceneManager")).transition_to_scene(NodePath("res://Town.tscn"))
	


func _on_Button_pressed():
	attack() # Replace with function body.
