extends CharacterBody2D

const box_pieces = preload("res://src/prefabs/box_pieces.tscn")

const fish_instance = preload("res://src/prefabs/fish_rigid.tscn")

@onready var animation_player := $anim as AnimationPlayer
@onready var spawn_fish := $spawn_fish as Marker2D
@export var pieces : PackedStringArray
@export var hitpoints := 3

@export var impulse := 200

func break_sprite():
	for piece in pieces.size():
		var piece_instance = box_pieces.instantiate()
		get_parent().add_child(piece_instance)
		piece_instance.get_node("texture").texture = load(pieces[piece])
		piece_instance.global_position = global_position
		piece_instance.apply_impulse(Vector2(randi_range(-impulse, impulse), randi_range(-impulse, -impulse * 2)))
		
	queue_free()
	
func create_fish():
	var fish = fish_instance.instantiate()
	get_parent().call_deferred("add_child", fish)
	fish.global_position = spawn_fish.global_position
	fish.apply_impulse(Vector2(randi_range(-50,50), -150))
	
	
	
