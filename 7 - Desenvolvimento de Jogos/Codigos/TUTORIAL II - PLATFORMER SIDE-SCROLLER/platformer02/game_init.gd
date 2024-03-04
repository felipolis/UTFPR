# Player
#	- Dano ao jogador
#
# Efeitos
#	- Partículas
#   - tela fade vermelha quando player leva dano
#
class_name GameInit
extends Node2D

@onready var _player: Player = $Player
#@onready var _keys_ui: TextureRect = $CanvasLayer/GameUI/KeysUI
@onready var _camera: CameraFollow = $Player/Camera2D

# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	# inject into game controller
#	game_controller.init(_player, _camera, _keys_ui)
	_camera.init_camera_limits(_get_map_bounds($TileMap))

	
func _get_map_bounds(tilemap) -> Rect2:
	var cell_rect: Rect2 = tilemap.get_used_rect()
	var pixel_size: float = tilemap.cell_quadrant_size * tilemap.scale.x
	
	var pos := Vector2(pixel_size * cell_rect.position.x, pixel_size * cell_rect.position.y)
	var size:= Vector2(pixel_size * cell_rect.size.x, pixel_size * cell_rect.size.y)
	
	return Rect2(pos, size)	
