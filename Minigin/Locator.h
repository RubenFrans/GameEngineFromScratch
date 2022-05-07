#pragma once

// TODO 
	// Reimplement without tempaltes
	// Now its possible to not use the interface and then we tightly couple again.

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
T* Locator<T>::m_pService{};
