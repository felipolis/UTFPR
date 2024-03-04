class_name CameraFollow
extends Camera2D

var _timer: Timer
var _shaking: bool = false
var _shake_range: float = 30

func _ready() -> void:
	_timer = Timer.new()
	add_child(_timer)
	_timer.timeout.connect(_stop_shaking)
	_timer.set_one_shot(true)
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta: float) -> void:
	if _shaking:
		offset = Vector2(
			randf_range(-_shake_range, _shake_range),
			randf_range(-_shake_range, _shake_range)
		)


func _stop_shaking() -> void:
	_shaking = false


func shake_camera(range: float, duration: float) -> void:
	_shaking = true
	_shake_range = range

	_timer.set_wait_time(duration)
	_timer.start()
