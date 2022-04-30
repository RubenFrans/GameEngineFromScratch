#pragma once
template <class T>
class Locator
{
public:
	static T* GetService() {
		return m_pService;
	}

	static void provide(T* pService) {
		m_pService = pService;
	}
private:
	static T* m_pService;
};

template <class T> 
T* Locator<T>::m_pService;
