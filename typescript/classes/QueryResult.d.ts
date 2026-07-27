declare global {
	namespace Acore {
		class QueryResult {
			readonly rowCount: number;
			readonly fieldCount: number;
			readonly allFields: Field[];

			getFieldName(i: number): string;
			getField(i: number): Field;
			nextRow(): boolean;
		}
	}
}
export {};
