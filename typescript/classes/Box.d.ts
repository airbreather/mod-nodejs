declare global {
	namespace Acore {
		class Box<T> {
			constructor(value: T);

			get(): T;
			set(value: T): void;
		}
	}
}
export {};
