t_shape	set_shape()
{
	t_shape	sh;

	sh.transform = m_identity();
	sh.material = m_create_material();
	return (sh);
}
