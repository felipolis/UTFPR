class_name Generator
extends StaticBody2D

@export var health: float = 10
@export var rotation_speed: float = 2
@export var generation_delay: float = 1.5
@export_file("*.tscn") var entity_scene: String

var _sprites: Array[Sprite2D]
var _entity_res: Resource
var _timer: Timer
var _player: Player
var _active: bool = false
var _tween: Tween

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	# get reference to all sprites 2D within this node
	for spr in get_children():
		if spr is Sprite2D:
			_sprites.append(spr)
			
	_entity_res = load(entity_scene)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	var offset: float = 0
	for spr in _sprites:
		spr.rotation += (rotation_speed + offset) * delta
		offset += 0.5
