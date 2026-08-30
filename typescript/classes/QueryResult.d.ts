declare global {
	namespace Acore {
		class QueryResult {
			readonly isEmpty: boolean;
			readonly rowCount: number;
			readonly fieldCount: number;
			readonly allFields: Field[];

			getFieldName(i: number): string;
			getField(i: number): Field;
			nextRow(): boolean;
		}
	}

	type EmptyQueryResult = { isEmpty: true };
	type MaybeQueryResult = EmptyQueryResult | (Acore.QueryResult & { isEmpty: false });
}
export {};
