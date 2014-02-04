#define PROP_READ_WRITE(type, x) \
	private: type m_##x; \
	public: void Set##x(type y) {m_##x = y;} \
	public: type Get#x() {return m_##x;}

#define PROP_READ_ONLY(type, x) \
	private: type m_##x; \
	private: void Set##x(type y) {m_##x = y;} \
	public: type Get##x() {return m_##x;}