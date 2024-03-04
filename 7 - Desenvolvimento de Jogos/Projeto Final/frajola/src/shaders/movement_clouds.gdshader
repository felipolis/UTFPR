shader_type canvas_item;

uniform float move_speed = 0.5;

void fragment() {
	// Place fragment code here.
	COLOR = texture(TEXTURE, vec2(UV.x + TIME * move_speed, UV.y));
}
