extends KinematicBody2D

export var walk_speed = 4.0
const TILE_SIZE = 16

signal player_entering_door_signal
signal player_entered_door_signal

onready var anim_tree = $AnimationTree
onready var anim_state = anim_tree.get("parameters/playback")
onready var blocking_ray = $BlockingRayCast2D
onready var door_ray = $DoorRayCast2D


var initial_position = Vector2(0,0)
var input_direction = Vector2(0,0)
var is_moving = false
var is_input_stopped = false
var percent_moved_to_next_tile = 0.0



# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	anim_tree.active = true
	initial_position = position
	pass # Replace with function body.

func _physics_process(delta):
	if is_input_stopped:
		return
	
	if is_moving == false:
		process_player_input()
	elif input_direction != Vector2.ZERO:
		anim_state.travel("Walk")
		move(delta)
	else:
		anim_state.travel("Idle")
		is_moving = false
		
func process_player_input():
	if input_direction.y == 0:
		input_direction.x = int(Input.is_action_pressed("ui_right")) - int(Input.is_action_pressed("ui_left"))
	if input_direction.x == 0:
		input_direction.y = int(Input.is_action_pressed("ui_down")) - int(Input.is_action_pressed("ui_up"))
		
		
	if input_direction != Vector2.ZERO:
		anim_tree.set("parameters/Idle/blend_position", input_direction)
		anim_tree.set("parameters/Walk/blend_position", input_direction)
		initial_position = position
		is_moving = true
	else:
		anim_state.travel("Idle")
		
		
func move(delta):
	var desired_step: Vector2 = input_direction * TILE_SIZE / 2
	blocking_ray.cast_to = desired_step
	blocking_ray.force_raycast_update()
	
	door_ray.cast_to = desired_step
	door_ray.force_raycast_update()
	
	if door_ray.is_colliding():
		if percent_moved_to_next_tile == 0.0:
			emit_signal("player_entering_door_signal")
		percent_moved_to_next_tile += walk_speed * delta
		if percent_moved_to_next_tile >= 1.0:
			position = initial_position + (input_direction * TILE_SIZE)
			percent_moved_to_next_tile = 0.0
			is_moving = false
			is_input_stopped = true
			emit_signal("player_entered_door_signal")
			$Camera2D.clear_current()
			
		else:
			position = initial_position + (input_direction * TILE_SIZE * percent_moved_to_next_tile)
			
			
	elif !blocking_ray.is_colliding():
		percent_moved_to_next_tile += walk_speed * delta
		if percent_moved_to_next_tile >= 1.0:
			position = initial_position + (TILE_SIZE * input_direction)
			percent_moved_to_next_tile = 0.0
			is_moving = false
		else:
			position = initial_position + (TILE_SIZE * input_direction * percent_moved_to_next_tile)
	else:
		is_moving = false
		

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
