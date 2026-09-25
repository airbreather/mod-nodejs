declare global {
	namespace Acore {
		class Box<T> {
			private constructor();

			get(): T;
			set(value: T): void;
		}
	}
}
export {};
