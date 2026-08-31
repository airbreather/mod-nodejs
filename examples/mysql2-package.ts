import mysql from 'mysql2/promise';

export function makeConnectionPool(db: Db) {
	const info = Acore.MySQLConnectionInfo.forDb(db);
	const options: mysql.PoolOptions = {
		user: info.user,
		password: info.password,
		database: info.database,
		supportBigNumbers: true,
		bigNumberStrings: false,
		multipleStatements: true,
	};
	if (info.ssl === 'ssl') {
		options.ssl = {};
	}
	const port = Number(info.port_or_socket);
	if (port) {
		options.host = info.host;
		options.port = port;
	} else {
		options.socketPath = info.port_or_socket;
	}
	return mysql.createPool(options);
}

export const LOGIN_DB = makeConnectionPool(Db.Login);
export const CHARACTER_DB = makeConnectionPool(Db.Character);
export const WORLD_DB = makeConnectionPool(Db.World);
export const PLAYERBOTS_DB = Acore.hasPlayerbotsModule() ? makeConnectionPool(Db.Playerbots) : undefined;

export function defaultConnectionPoolFor(db: Db) {
	switch (db) {
		case Db.Login:
			return LOGIN_DB;
		case Db.Character:
			return CHARACTER_DB;
		case Db.World:
			return WORLD_DB;
		case Db.Playerbots:
			return PLAYERBOTS_DB;
	}
}

export async function inTransaction<T>(db: Db, cb: (conn: mysql.PoolConnection) => Promise<T>) {
	const pool = defaultConnectionPoolFor(db);
	if (!pool) {
		throw new Error('Db not present');
	}
	const conn = await pool.getConnection();
	await conn.beginTransaction();
	try {
		const ret = await cb(conn);
		await conn.commit();
		return ret;
	} catch (err) {
		await conn.rollback();
		throw err;
	}
}
