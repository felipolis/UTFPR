extends Node2D

@onready var frajola := $frajola as CharacterBody2D
@onready var camera := $camera as Camera2D
@onready var control = $HUD/control


# Called when the node enters the scene tree for the first time.
func _ready():
	frajola.follow_camera(camera)
	get_tree().call_group("boss", "set_frajola", frajola)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	pass
