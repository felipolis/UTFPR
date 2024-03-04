class_name CameraFollow
extends Camera2D


var _timer: Timer
var _shaking: bool = false
var _shake_range: float = 5


# Called when the node enters the scene tree for the first time.
func _ready() -> void:
	pass


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(_delta: float) -> void:
	if _shaking:
		offset = Vector2(randf_range(-_shake_range, _shake_range), randf_range(-_shake_range, _shake_range))


func _stop_shaking() -> void:
	_shaking = false


func shake_camera(amount: float, duration: float) -> void:
	if _timer:
		_timer.stop()
	else:
		_timer = Timer.new()
		add_child(_timer)
		_timer.timeout.connect(_stop_shaking)

	_shaking = true
	_shake_range = amount
	
	_timer.set_wait_time(duration)
	_timer.set_one_shot(true)
	_timer.start()


func init_camera_limits(map_bounds: Rect2) -> void:
	# inject into player's camera
	set_limit(Side.SIDE_LEFT, int(map_bounds.position.x))
	set_limit(Side.SIDE_RIGHT, int(map_bounds.size.x + map_bounds.position.x))
	set_limit(Side.SIDE_TOP, int(map_bounds.position.y))
	set_limit(Side.SIDE_BOTTOM, int(map_bounds.size.y + map_bounds.position.y))
