declare global {
	namespace Acore {
		class MySQLConnectionInfo {
			constructor(cfg: string);

			static forDb(db: Db): MySQLConnectionInfo;

			readonly user: string;
			readonly password: string;
			readonly database: string;
			readonly host: string;
			readonly port_or_socket: string;
			readonly ssl: string;
		}
	}
}
export {};
